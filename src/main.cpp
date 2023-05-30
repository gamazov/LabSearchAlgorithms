/*!
\file
\brief https://github.com/gamazov/LabSearchAlgorithms
\author Mazov Grigiriy
*/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

/*!
\fn void parseStr(std::string input, std::vector<std::string> &output, char sym)
\brief Finds elements separated by the sym symbol in the string str and writes the result to output
\param[in] input The string in which the search is performed
\param[in,out] output Found substrings
\param[in] sym The character by which to divide the string
*/

/*!
\fn void parseNo(Train &train)
\brief Converts the string no to an unsigned number for comparison
\param[in,out] train Structure to be filled in
*/

/*!
\fn void parseData(Train &train)
\brief Converts the data string to an unsigned number for comparison
\param[in,out] train Structure to be filled in
*/

/*!
\fn void parseTime(Train &train)
\brief Converts the string time to an unsigned number for comparison
\param[in,out] train Structure to be filled in
*/

/*!
\fn void parseOnRoad(Train &train)
\brief Converts the string on Road to an unsigned number for comparison
\param[in,out] train Structure to be filled in
*/

/*!
\fn void parseFile(std::vector<Train> &schedules, char *fileName)
\brief All schedule entries are filled in by reading data from the transmitted file
\param[in,out] schedules Schedule to be filled in
\param[in] fileName The file in which the search takes place
*/

/*!
\fn void printSchedules(std::vector<Train> &schedules)
\brief Displays the entire schedule
\param[in] schedules Schedule
*/

/*!
\fn void printFileSchedules(std::vector<Train> &schedules, std::vector<int> &pos);
\brief Writes to a file output.txt
\param[in] schedules Schedule
\param[in] pos Positions in schedule
*/

/*!
\fn void merge(std::vector<Train> &schedules, int start, int end, int mid)
\brief Combining arrays
\param[in,out] schedules Sortable schedule
\param[in] start The beginning of the sorted array
\param[in] end End of the sorted array
\param[in] mid The middle of the sorted array
*/

/*!
\fn void mergeSort(std::vector<Train> &schedules, int start, int end)
\brief Merge sort
\param[in,out] schedules Sortable schedule
\param[in] start The beginning of the sorted array
\param[in] end End of the sorted array
*/

/*!
\fn int findFirst(std::vector<Train> &schedules, int start, int end, std::string find)
\brief Search for the index of the first counter element
\param[in] schedules Schedules in which the search is performed
\param[in] start The beginning of the subarray
\param[in] end The end of the subarray
\param[in] find The key you are looking for
*/

/*!
\fn std::vector<int> linearSearch(std::vector<Train> &schedules, std::string find)
\brief Linear search function
\param[in] schedules Schedules in which the search is performed
\param[in] find The key you are looking for
*/
 
/*!
\fn int firstBinarySearch(std::vector<Train> &schedules, int start, int end, std::string value)
\brief Search by the key of the beginning of the subarray of the sorted array
\param[in] schedules Schedules in which the search is performed
\param[in] start The beginning of the subarray
\param[in] end The end of the subarray
\param[in] find The key you are looking for
*/

/*!
\fn int lastBinarySearch(std::vector<Train> &schedules, int start, int end, std::string value)
\brief Search by the key of the end of the subarray of the sorted array
\param[in] schedules Schedules in which the search is performed
\param[in] start The beginning of the subarray
\param[in] end The end of the subarray
\param[in] find The key you are looking for
*/
 
/*!
\fn std::vector<int> binarySearch(std::vector<Train> &schedules, int start, int end, std::string value)
\brief Searching by the key of a subarray of a sorted array
\param[in] schedules Schedules in which the search is performed
\param[in] start The beginning of the subarray
\param[in] end The end of the subarray
\param[in] find The key you are looking for
*/

/*!
\brief Describes the recording of the train schedule
*/
struct Train {
  //! Departure date
  std::string data;
  //! Departure time
  std::string time;
  //! Train number
  std::string no;
  //! Travel time
  std::string onRoad;
  //! Type of train
  std::string type;

  //! Date represented as an unsigned number for comparison
  unsigned int dataVal = 0;
  //! Departure time, represented as an unsigned number for comparison
  unsigned int timeVal = 0;
  //! A number represented as an unsigned number for comparison
  unsigned int noVal = 0;
  //! Travel time, represented as an unsigned number for comparison
  unsigned int onRoadVal = 0;
};

void parseFile(std::vector<Train> &schedules, char *fileName);
void parseStr(std::string input, std::vector<std::string> &output, char sym);
void parseNo(Train &train);
void parseData(Train &train);
void parseTime(Train &train);
void parseOnRoad(Train &train);
void parseType(Train &train);

bool operator==(Train &f, Train &s);
bool operator>(Train &f, Train &s);
bool operator<(Train &f, Train &s);
bool operator>=(Train &f, Train &s);
bool operator<=(Train &f, Train &s);

bool operator<(std::string &f, std::string &s);

void merge(std::vector<Train> &schedules, int start, int end, int mid);
void mergeSort(std::vector<Train> &schedules, int start, int end);

int findFirst(std::vector<Train> &schedules, int start, int end, std::string find);
std::vector<int> linearSearch(std::vector<Train> &schedules, std::string find);

int firstBinarySearch(std::vector<Train> &schedules,
                      int start,
                      int end,
                      std::string value);
int lastBinarySearch(std::vector<Train> &schedules,
                     int start,
                     int end,
                     std::string value);
std::vector<int> binarySearch(std::vector<Train> &schedules,
                              int start,
                              int end,
                              std::string value);

void printSchedules(std::vector<Train> &schedules);
void printFileSchedules(std::vector<Train> &schedules, std::vector<int> &pos);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Parametrs error";
    return 1;
  }
  std::vector<Train> schedules;

  parseFile(schedules, argv[1]);
  std::string find = argv[2];
    
  unsigned int endTime = 0, startTime = 0;
#ifdef LINEAR
  startTime = clock();
  std::vector<int> res = linearSearch(schedules, find);
  endTime = clock();
  printFileSchedules(schedules, res);
#endif // LINEAR
#ifdef BINARYSORTED
  mergeSort(schedules, 0, static_cast<int>(schedules.size()) - 1);
  startTime = clock();
  std::vector<int> res = binarySearch(schedules, 0, static_cast<int>(schedules.size()), find);
  endTime = clock();
  printFileSchedules(schedules, res);
#endif // BINARYSORTED
#ifdef BINARYANDSORT
  startTime = clock();
  mergeSort(schedules, 0, static_cast<int>(schedules.size()) - 1);
  std::vector<int> res = binarySearch(schedules, 0, static_cast<int>(schedules.size()), find);
  endTime = clock();
  printFileSchedules(schedules, res);
#endif // BINARYANDSORT
#ifdef MULTIMAP
  std::multimap<std::string, int> mmap;
    for (int i = 0; i < static_cast<int>(schedules.size()); i++) {
        mmap.insert(std::pair<std::string, int>{schedules[i].type, i});
    }
    
    startTime = clock();
    auto range = mmap.equal_range(find);
    endTime = clock();
    
    std::ofstream fout("output.txt");
    for (auto i = range.first; i != range.second; i++) {
        fout << schedules[i->second].no << " " << schedules[i->second].data << " " << schedules[i->second].type << " " << schedules[i->second].time << " " << schedules[i->second].onRoad << std::endl;
    }
    fout.close();
#endif // MULTIMAP
  unsigned int searchTime = 1000000.0 * (endTime - startTime) / CLOCKS_PER_SEC;
  std::cout << "Execution time for " << schedules.size() << ": " << searchTime << std::endl;

  return 0;
}

int findFirst(std::vector<Train> &schedules, int start, int end, std::string find) {
  for (int i = start; i < end; i++) {
    if (schedules[i].type == find) {
      return i;
    }
  }
  return -2;
}

std::vector<int> linearSearch(std::vector<Train> &schedules, std::string find) {
  std::vector<int> output = {};

  int pos = -1;
  while (pos != -2) {
    pos = findFirst(schedules, pos + 1, static_cast<int>(schedules.size()), find);
    if (pos != -2) {
      output.push_back(pos);
    }
  }
  return output;
}

bool operator<(std::string &f, std::string &s) {
  int fVal = 0, sVal = 0;
  if (f == "express") {
    fVal = 0;
  }
  if (f == "passenger") {
    fVal = 1;
  }
  if (f == "freight") {
    fVal = 2;
  }
  if (s == "express") {
    sVal = 0;
  }
  if (s == "passenger") {
    sVal = 1;
  }
  if (s == "freight") {
    sVal = 2;
  }
  return fVal < sVal;
}

int firstBinarySearch(std::vector<Train> &schedules,
                      int start,
                      int end,
                      std::string value) {
  if (start >= end) {
    return -1;
  }

  if (value == schedules[start].type) {
    return start;
  }
  int mid = start + (end - start) / 2;
  if (value == schedules[mid].type) {
    if (mid - start <= 1) {
      return mid;
    }
    else {
      return firstBinarySearch(schedules, start, mid + 1, value);
    }
  }
  if (value < schedules[mid].type) {
    return firstBinarySearch(schedules, start, mid, value);
  }
  else {
    return firstBinarySearch(schedules, mid + 1, end, value);
  }
}

int lastBinarySearch(std::vector<Train> &schedules,
                     int start,
                     int end,
                     std::string value) {
  if (start >= end) {
    return -1;
  }

  int last = end - 1;
  if (value == schedules[last].type) {
    return last;
  }
  int mid = start + (end - start) / 2;
  if (value == schedules[mid].type) {
    if (last - mid <= 1) {
      return mid;
    }
    else {
      return lastBinarySearch(schedules, mid, end, value);
    }
  }
  if (value < schedules[mid].type) {
    return lastBinarySearch(schedules, start, mid, value);
  }
  else {
    return lastBinarySearch(schedules, mid + 1, end, value);
  }
}

std::vector<int> binarySearch(std::vector<Train> &schedules,
                              int start,
                              int end,
                              std::string value) {
  if (start >= end) {
    std::vector<int> output = {};
    return output;
  }

  int mid = start + (end - start) / 2;
  if (value == schedules[mid].type) {
    auto pair = std::make_pair(firstBinarySearch(schedules, start, end, value),
                               lastBinarySearch(schedules, start, end, value));
    std::vector<int> output = {};
    for (int i = pair.first; i <= pair.second; i++) {
      output.push_back(i);
    }
    return output;
  }
  if (value < schedules[mid].type) {
    return binarySearch(schedules, start, mid, value);
  }
  else {
    return binarySearch(schedules, mid + 1, end, value);
  }
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
    parseType(train);
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

void parseType(Train &train) {
  if (train.type == "express") {
    train.typeVal = 0;
  }
  if (train.type == "passenger") {
    train.typeVal = 1;
  }
  if (train.type == "freight") {
    train.typeVal = 2;
  }
}

bool operator==(Train &f, Train &s) {
  if (f.typeVal == s.typeVal) {
    return true;
  }
  return false;
}

bool operator>(Train &f, Train &s) {
  if (f.typeVal > s.typeVal) {
    return true;
  }
  return false;
}

bool operator<(Train &f, Train &s) {
  if (f.typeVal < s.typeVal) {
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
  for (int i = 0; i < static_cast<int>(schedules.size()); i++) {
    std::cout << schedules[i].no << " " << schedules[i].data << " " << schedules[i].type << " " << schedules[i].time << " " << schedules[i].onRoad << std::endl;
  }
}

void printFileSchedules(std::vector<Train> &schedules, std::vector<int> &pos) {
  std::ofstream fout("output.txt");

  for (int i = 0; i < static_cast<int>(pos.size()); i++) {
    fout << schedules[pos[i]].no << " " << schedules[pos[i]].data << " " << schedules[pos[i]].type << " " << schedules[pos[i]].time << " " << schedules[pos[i]].onRoad << std::endl;
  }

  fout.close();
}
