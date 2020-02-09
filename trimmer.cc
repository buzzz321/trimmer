#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

const char *trimC(char *data)
{
  auto len = strlen(data);

  std::size_t lindex = 0;
  std::size_t rindex = 0;

  for (lindex = 0; lindex < len; ++lindex)
  {
    if (!isspace(data[lindex]))
    {
      break;
    }
  }
  for (rindex = len - 1; rindex > 0; rindex--)
  {
    if (!isspace(data[rindex]))
    {
      break;
    }
  }
  rindex++;

  if (lindex >= rindex)
  {
    return "";
  }

  if (lindex == len)
  {
    return data;
  }

  *(data + rindex) = 0;
  return data + lindex;
}

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
    if (!isspace(data[lindex]))
    {
      break;
    }
  }
  for (rindex = len - 1; rindex > 0; rindex--)
  {
    if (!isspace(data[rindex]))
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

  char str[] = "   Hejsan hoppsan    ";
  std::cout << "Tjo |" << trimC(str) << "|" << std::endl;

  memset(str, 0, strlen(str));
  strncpy(str, "", 21);
  std::cout << "Tjo |" << trimC(str) << "|" << std::endl;

  memset(str, 0, strlen(str));
  strncpy(str, " ", 21);
  std::cout << "Tjo |" << trimC(str) << "|" << std::endl;

  memset(str, 0, strlen(str));
  strncpy(str, "       ", 21);
  std::cout << "Tjo |" << trimC(str) << "|" << std::endl;

  return 0;
}
