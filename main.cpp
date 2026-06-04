#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace {

void usage(const char *program) {
  cerr << "Usage: " << program
       << " --encrypt|--decrypt --key N --input FILE [--output FILE]\n"
       << "If --output is omitted, the input file is updated in place.\n";
}

vector<char> read_file(const string &path) {
  ifstream in(path, ios::binary);
  if (!in) {
    throw runtime_error("Unable to open input file: " + path);
  }
  return vector<char>((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
}

void write_file(const string &path, const vector<char> &data) {
  ofstream out(path, ios::binary | ios::trunc);
  if (!out) {
    throw runtime_error("Unable to open output file: " + path);
  }
  out.write(data.data(), static_cast<streamsize>(data.size()));
}

vector<char> xor_data(const vector<char> &input, int key) {
  vector<char> output;
  output.reserve(input.size());
  for (char byte : input) {
    output.push_back(static_cast<char>(byte ^ key));
  }
  return output;
}

} // namespace

int main(int argc, char **argv) {
  bool has_mode = false;
  int key = -1;
  string input_path;
  string output_path;

  for (int i = 1; i < argc; ++i) {
    string arg = argv[i];
    if (arg == "--encrypt" || arg == "--decrypt") {
      has_mode = true;
    } else if (arg == "--key" && i + 1 < argc) {
      key = stoi(argv[++i]);
    } else if (arg == "--input" && i + 1 < argc) {
      input_path = argv[++i];
    } else if (arg == "--output" && i + 1 < argc) {
      output_path = argv[++i];
    } else if (arg == "--help") {
      usage(argv[0]);
      return 0;
    } else {
      usage(argv[0]);
      return 2;
    }
  }

  if (!has_mode || key < 0 || key > 255 || input_path.empty()) {
    usage(argv[0]);
    return 2;
  }

  if (output_path.empty()) {
    output_path = input_path;
  }

  try {
    vector<char> input = read_file(input_path);
    vector<char> output = xor_data(input, key);
    write_file(output_path, output);
    cout << "Wrote " << output.size() << " bytes to " << output_path << "\n";
  } catch (const exception &error) {
    cerr << error.what() << "\n";
    return 1;
  }

  return 0;
}
