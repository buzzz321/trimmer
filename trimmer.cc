#include <iostream>
#include <string>

std::string trim(std::string &data)
{
  auto len = data.length();
  std::size_t lindex = 0;
  std::size_t rindex = 0;

  if (len == 0)
  {
    return "";
  }
  for (lindex = 0; lindex < len; ++lindex)
  {
    if (data[lindex] != ' ')
    {
      break;
    }
  }
  for (rindex = len - 1; rindex > 0; rindex--)
  {
    if (data[rindex] != ' ')
    {
      break;
    }
  }
  rindex++;

  if (lindex == len)
  {
    return std::string();
  }
  return data.substr(lindex, rindex - lindex);
}

int main()
{
  std::string data = "   Hejsan hoppsan    ";
  std::cout << "Tjo |" << trim(data) << "|" << std::endl;

  data = "       ";
  std::cout << "Tjo |" << trim(data) << "|" << std::endl;

  data = " ";
  std::cout << "Tjo |" << trim(data) << "|" << std::endl;

  data = "";
  std::cout << "Tjo |" << trim(data) << "|" << std::endl;

  return 0;
}
