#include<iostream>


class IntArrayElement{
  int _data;
  IntArrayElement* _next;

  public:


  IntArrayElement(int data){
    _data = data;
    _next = nullptr;
    std::cout << "IntArrayElement erzeugt\n";
  }
  ~IntArrayElement(){
    std::cout << "IntArrayElement zerstört\n";
    delete _next;
  };

  void set_data(int data){
    _data = data;
  }
  void set_next(IntArrayElement* next){
    _next = next;
  }

  int get_data(){
    return _data;
  }

  IntArrayElement* get_next(){
    return _next;
  } 


};


class ArrayElement{
  IntArrayElement* _root;

  public:
  ArrayElement(){
    _root = nullptr;
  }
  ~ArrayElement(){

    delete _root;
  };
  void push_back(int data){
    IntArrayElement* new_element = new IntArrayElement(data);

    if (_root == nullptr) {
      _root = new_element;
    } else {
      IntArrayElement* _temp = _root;
      while(_temp->get_next() != nullptr){
        _temp = _temp->get_next();
      }
      _temp->set_next(new_element);

    }

  };

  int size(){
    int size = 0;
    IntArrayElement* _temp = _root;
    while(_temp != nullptr){
      _temp = _temp->get_next();
      size++;
    }
    return size;
  };

  int at(int position){
    IntArrayElement* _temp = _root;
    for(int i = 0; i < position; i++){
      _temp = _temp->get_next();
    }
    return _temp->get_data();
  };

};


int main()
{
  std::cout << "Gleich geht es rein...\n";
  {
    ArrayElement dynIntArray;
    dynIntArray.push_back(10);
    dynIntArray.push_back(20);
    dynIntArray.push_back(30);
    std::cout << "size: " << dynIntArray.size() << std::endl;
    for (int i = 0; i < dynIntArray.size(); i++)
    {
      std::cout << i << ": " << dynIntArray.at(i) << std::endl;
    }
  }
  std::cout << "Jetzt wieder draussen...\n";
  return 0;
}