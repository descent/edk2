#include  "myvec.h"
#include  "myiostream.h"
#include "my_setjmp.h"
using namespace DS;

class Obj
{
  public:
    Obj()
    {
      i=10;
      ::printf("ctor\n");
    }
    ~Obj()
    {
      ::printf("dtor\n");
    }
  private:
    int i;
};

jmp_buf jbuf;

int lambda_test(int girls = 3, int boys = 4)
{
  auto totalChild = [](int x, int y) ->int{return x+y;};
  return totalChild(girls, boys);
}

int main (IN int Argc, IN char **Argv)
{
  Obj obj;

  int total = lambda_test();
  cout << "total: " << total << endl;

  vector<int> vec_i;

  vec_i.push_back(1);
  vec_i.push_back(2);
  vec_i.push_back(3);
  for (int i=0 ; i < vec_i.size() ; ++i)
    cout << vec_i[i] << endl;

  char *area = (char*)mymalloc(20);
  char *a1 = new char [20];

  int j_ret = 9;
  //printf("aaa\n");
  //getchar();
  j_ret = my_setjmp(jbuf);

  if (j_ret == 0)
  {
    printf("00\n");
  }
  else 
  {
    printf("11\n");
    return 0;
  }

  my_longjmp(jbuf, 5);
  return 0;
}
