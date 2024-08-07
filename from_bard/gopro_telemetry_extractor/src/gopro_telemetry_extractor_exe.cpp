#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct GPMDData {
  int timestamp;
  float latitude;
  float longitude;
  float altitude;
  float speed;
  float heading;
  float pitch;
  float roll;
};

int main(int argc, char* argv[]) {

  if (argc < 2){
    cout<<"Incorrect usage. ./gopro_telemetry_extractor_exe path/to/video_file.MP4"<<endl;
  }

  string filename = argv[1];

  ifstream input_file(filename, ios::binary);
  if (!input_file.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return 1;
  }

  // Read the GPMD header.
  int header_size;
  input_file.read((char*)&header_size, sizeof(header_size));

  // Read the GPMD data.
  vector<GPMDData> data;
  for (int i = 0; i < header_size; i++) {
    GPMDData gpmd_data;
    input_file.read((char*)&gpmd_data, sizeof(gpmd_data));
    data.push_back(gpmd_data);
    cout<< i << endl;
  }

  // Write the GPMD data to a CSV file.
  ofstream output_file(filename+".csv");
  output_file << "timestamp,latitude,longitude,altitude,speed,heading,pitch,roll" << endl;
  for (int i = 0; i < data.size(); i++) {
    output_file << data[i].timestamp << "," << data[i].latitude << "," << data[i].longitude << "," << data[i].altitude << "," << data[i].speed << "," << data[i].heading << "," << data[i].pitch << "," << data[i].roll << endl;
  }

  return 0;
}
