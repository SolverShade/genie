#include <regex>
#include <utillities/TextParsing.hpp>

using namespace std;

TextParsing::TextParsing() {}

string TextParsing::GetFileName(string filePath) {
  regex fileNameRegex(".*[\\/](.+)");
  smatch match;

  if (regex_search(filePath, match, fileNameRegex)) {
    return match[1].str();
  }

  return "";
}
