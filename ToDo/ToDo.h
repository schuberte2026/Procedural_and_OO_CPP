//
// Created by schuberte on 10/7/2024.
//
#include<string>
#ifndef TODO_H
#define TODO_H

class ToDo {
  private:
    static constexpr int MAXITEMS = 100;
    std::string items[MAXITEMS];
    int count;


  public:
    ToDo();
    ToDo(std::string first_item);
    bool empty();
    bool full();
    void add(std::string next_item);
    std::string next_item();
    std::string next_item_capitalized();
    std::string operator[](int ix);

};



#endif //TODO_H
