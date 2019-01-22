#include <iostream>
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {5, 9, 8, 3, 0, 1, 4};
  while(std::next_permutation(myints, myints + 7)) {
  for(int i = 0; i < 7; i++) {
      std::cout<<myints[i]<<" ";
  }
  std::cout<<std::endl;
  }
  return 0;
}
