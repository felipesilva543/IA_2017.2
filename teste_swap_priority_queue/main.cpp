// swap priority_queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue, std::swap(priority_queue)

using namespace std;
int main ()
{
  priority_queue<int> foo,bar;
  foo.push (15); foo.push(30); foo.push(10);
  //bar.push (101); bar.push(202);
  cout << "size of foo: " << foo.size() << '\n';
  cout << "size of bar: " << bar.size() << '\n';

  cout << "------------------------------" << endl;

  swap(foo,bar);

  cout << "size of foo: " << foo.size() << '\n';
  cout << "size of bar: " << bar.size() << '\n';

  cout << "------------------------------" << endl;
  cout << "Foo:" << endl;
  while(!foo.empty()){
      cout << foo.top() << " ";
      foo.pop();
  }

  cout << endl << "------------------------------" << endl;
  cout << "Bar:" << endl;
  while(!bar.empty()){
      cout << bar.top() << " ";
      bar.pop();
  }
  cout << endl;
  return 0;
}

