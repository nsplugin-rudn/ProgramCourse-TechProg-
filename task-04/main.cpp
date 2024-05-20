#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Laptop {
  string brand;
  string model;
  int year;
  string processor;
  double price;
};

vector<Laptop> laptops;

void loadFromFile(const string &filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    return;
  }

  laptops.clear();
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    Laptop laptop;
    getline(ss, laptop.brand, ',');
    getline(ss, laptop.model, ',');
    ss >> laptop.year;
    ss.ignore();
    getline(ss, laptop.processor, ',');
    ss >> laptop.price;
    laptops.push_back(laptop);
  }

  file.close();
}

void saveToFile(const string &filename) {
  ofstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    return;
  }

  for (const auto &laptop : laptops) {
    file << laptop.brand << "," << laptop.model << "," << laptop.year << ","
         << laptop.processor << "," << laptop.price << endl;
  }

  file.close();
}

void addLaptop() {
  Laptop laptop;
  cout << "Enter brand: ";
  cin >> laptop.brand;
  cout << "Enter model: ";
  cin >> laptop.model;
  cout << "Enter year: ";
  cin >> laptop.year;
  cout << "Enter processor: ";
  cin >> laptop.processor;
  cout << "Enter price: ";
  cin >> laptop.price;
  laptops.push_back(laptop);
}

void editLaptop() {
  int index;
  cout << "Enter the index of the laptop to edit: ";
  cin >> index;
  if (index < 0 || index >= laptops.size()) {
    cout << "Invalid index!" << endl;
    return;
  }

  cout << "Enter new brand: ";
  cin >> laptops[index].brand;
  cout << "Enter new model: ";
  cin >> laptops[index].model;
  cout << "Enter new year: ";
  cin >> laptops[index].year;
  cout << "Enter new processor: ";
  cin >> laptops[index].processor;
  cout << "Enter new price: ";
  cin >> laptops[index].price;
}

void deleteLaptop() {
  int index;
  cout << "Enter the index of the laptop to delete: ";
  cin >> index;
  if (index < 0 || index >= laptops.size()) {
    cout << "Invalid index!" << endl;
    return;
  }

  laptops.erase(laptops.begin() + index);
}

void searchLaptop() {
  string query;
  cout << "Enter brand or model to search: ";
  cin >> query;

  for (const auto &laptop : laptops) {
    if (laptop.brand == query || laptop.model == query) {
      cout << "Brand: " << laptop.brand << ", Model: " << laptop.model
           << ", Year: " << laptop.year << ", Processor: " << laptop.processor
           << ", Price: " << laptop.price << endl;
    }
  }
}

void printLaptops() {
  for (size_t i = 0; i < laptops.size(); ++i) {
    cout << "Index: " << i << ", Brand: " << laptops[i].brand
         << ", Model: " << laptops[i].model << ", Year: " << laptops[i].year
         << ", Processor: " << laptops[i].processor
         << ", Price: " << laptops[i].price << endl;
  }
}

int main() {
  string filename = "laptops.txt";
  loadFromFile(filename);

  while (true) {
    cout << "\n1. Add laptop\n"
         << "2. Edit laptop\n"
         << "3. Delete laptop\n"
         << "4. Search laptop\n"
         << "5. Print all laptops\n"
         << "6. Save and exit\n"
         << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      addLaptop();
      break;
    case 2:
      editLaptop();
      break;
    case 3:
      deleteLaptop();
      break;
    case 4:
      searchLaptop();
      break;
    case 5:
      printLaptops();
      break;
    case 6:
      saveToFile(filename);
      return 0;
    default:
      cout << "Invalid choice!" << endl;
    }
  }

  return 0;
}
