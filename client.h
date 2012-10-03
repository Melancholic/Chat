#ifndef CLIENT_H
#define CLIENT_H
#include<vector>
extern const int MaxLenMsg;
extern const int MaxLenAdresat;
class client{
 char *msg;
 char *adresat;
 char *pass;
 char *nickname;
public:
  client();
  ~client();
  void login();
  void add_msg();
  char GetSymMsg(int i);
};
#endif