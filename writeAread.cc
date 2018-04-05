#include <iostream>
#include <string>
#include "my.helloworld.pb.h"

using namespace std;

int main(int argc, char* argv[]){
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  my::helloworld hw;

  hw.set_id(1);
  hw.set_str("1");
  hw.set_wow(1);

  string serializedStr;
  hw.SerializeToString(&serializedStr); 
  cout<< "ser ok!" <<endl;

  // deserialize
  my::helloworld deserializedhw;
  if(!deserializedhw.ParseFromString(serializedStr)){
    cerr << "Failed parse" <<endl; 
    return -1;
  }
  cout << deserializedhw.DebugString() <<endl;
  cout << "id" <<deserializedhw.id() <<endl;
  cout << "str" <<deserializedhw.str() <<endl;
  cout << "wow" <<deserializedhw.wow() <<endl;



}
