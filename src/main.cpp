#include <fstream>
#include <iostream>
#include <vector>

struct Train {
  std::string data;
  std::string time;
  std::string no;
  std::string onRoad;
  std::string type;

  unsigned int dataVal = 0;
  unsigned int timeVal = 0;
  unsigned int noVal = 0;
  unsigned int onRoadVal = 0;
};

void parseFile(std::vector<Train> &schedules, char *fileName);
void parseStr(std::string input, std::vector<std::string> &output, char sym);
void parseNo(Train &train);
void parseData(Train &train);
void parseTime(Train &train);
void parseOnRoad(Train &train);

bool operator==(Train &f, Train &s);
bool operator>(Train &f, Train &s);
bool operator<(Train &f, Train &s);
bool operator>=(Train &f, Train &s);
bool operator<=(Train &f, Train &s);

void merge(std::vector<Train> &schedules, int start, int end, int mid);
void mergeSort(std::vector<Train> &schedules, int start, int end);

void printSchedules(std::vector<Train> &schedules);
void printInfo(std::vector<Train> &schedules, std::string fileName);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "No parametrs";
    return 1;
  }
  std::vector<Train> schedules;
  parseFile(schedules, argv[1]);

  unsigned int endTime, startTime = clock();
    
  mergeSort(schedules, 0, static_cast<int>(schedules.size()) - 1);

  endTime = clock();

  std::ofstream fout("output.txt");
  for (size_t i = 0; i < schedules.size(); i++) {
    fout << i << ": " << schedules[i].no << " " << schedules[i].data << " " << schedules[i].type << " " << schedules[i].time << " " << schedules[i].onRoad << std::endl;
  }
  fout.close();

  unsigned int searchTime = 1000.0 * (endTime - startTime) / CLOCKS_PER_SEC;
  std::cout << "Execution time " << "output.txt" << " for " << schedules.size() << ": " << searchTime << std::endl;

  return 0;
}

void parseFile(std::vector<Train> &schedules, char *fileName) {
  std::ifstream fin;
  fin.open(fileName);

  char buf[100] = "";
  while (1) {
    fin.getline(buf, 100);
    if (strlen(buf) == 0) {
      break;
    }
    Train train = {};
    std::string str = buf;

    std::vector<std::string> parsedStrs = {};
    parseStr(str, parsedStrs, ' ');
    train.no = parsedStrs[0];
    train.data = parsedStrs[1];
    train.type = parsedStrs[2];
    train.time = parsedStrs[3];
    train.onRoad = parsedStrs[4];

    parseNo(train);
    parseData(train);
    parseTime(train);
    parseOnRoad(train);

    schedules.push_back(train);
  }

  fin.close();
}

void parseStr(std::string input, std::vector<std::string> &output, char sym) {
  unsigned int pos = 0;
  while (input.find(sym, 0) != std::string::npos) {
    pos = input.find(sym, 0);
    output.push_back(input.substr(0, pos));

    input.erase(0, pos + 1);
  }
  output.push_back(input);
}

void parseNo(Train &train) { train.noVal = std::stoi(train.no); }

void parseData(Train &train) {
  std::vector<std::string> parsedStrs = {};
  parseStr(train.data, parsedStrs, '.');

  train.dataVal = 10000 * std::stoi(parsedStrs[2]) + 100 * std::stoi(parsedStrs[1]) + std::stoi(parsedStrs[0]);
}

void parseTime(Train &train) {
  std::vector<std::string> parsedStrs = {};
  parseStr(train.time, parsedStrs, ':');

  train.timeVal = std::stoi(parsedStrs[0] + parsedStrs[1] + parsedStrs[2]);
}

void parseOnRoad(Train &train) {
  std::vector<std::string> parsedStrs = {};
  parseStr(train.onRoad, parsedStrs, ':');

  train.onRoadVal = std::stoi(parsedStrs[0] + parsedStrs[1] + parsedStrs[2]);
}

bool operator==(Train &f, Train &s) {
  if (f.dataVal == s.dataVal && f.timeVal == s.timeVal && f.noVal == s.noVal && f.onRoadVal == s.onRoadVal) {
    return true;
  }
  return false;
}

bool operator>(Train &f, Train &s) {
  if (f.dataVal > s.dataVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal > s.timeVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal == s.timeVal && f.noVal > s.noVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal == s.timeVal && f.noVal == s.noVal && f.onRoadVal > s.onRoadVal) {
    return true;
  }
  return false;
}

bool operator<(Train &f, Train &s) {
  if (f.dataVal < s.dataVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal < s.timeVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal == s.timeVal && f.noVal < s.noVal) {
    return true;
  }
  if (f.dataVal == s.dataVal && f.timeVal == s.timeVal && f.noVal == s.noVal && f.onRoadVal < s.onRoadVal) {
    return true;
  }
  return false;
}

bool operator>=(Train &f, Train &s) {
  if (f == s) {
    return true;
  }
  if (f > s) {
    return true;
  }
  return false;
}

bool operator<=(Train &f, Train &s) {
  if (f == s) {
    return true;
  }
  if (f < s) {
    return true;
  }
  return false;
}

void merge(std::vector<Train> &schedules, int start, int end, int mid) {
  Train *tmp = new Train[end - start + 1];
  int i = start, j = mid + 1, k = 0;

  while ((i <= mid) && (j <= end)) {
    if (schedules[i] <= schedules[j]) {
      tmp[k] = schedules[i];
      i++;
    } else {
      tmp[k] = schedules[j];
      j++;
    }
    k++;
  }
  if (i > mid) {
    for (int h = j; h <= end; h++) {
      tmp[k] = schedules[h];
      k++;
    }
  } else {
    for (int h = i; h <= mid; h++) {
      tmp[k] = schedules[h];
      k++;
    }
  }
  for (int h = 0; h <= end - start; h++) {
    schedules[h + start] = tmp[h];
  }
  delete[] tmp;
}
void mergeSort(std::vector<Train> &schedules, int start, int end) {
  if (start < end) {
    long mid = (start + end) / 2;
    mergeSort(schedules, start, mid);
    mergeSort(schedules, mid + 1, end);
    merge(schedules, start, end, mid);
  }
}

void printSchedules(std::vector<Train> &schedules) {
  std::cout << std::endl;
  for (size_t i = 0; i < schedules.size(); i++) {
    std::cout << i << ": " << schedules[i].no << " " << schedules[i].data << " " << schedules[i].type << " " << schedules[i].time << " " << schedules[i].onRoad << std::endl;
  }
}
