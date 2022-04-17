// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
T arr[100];
int first, last;
 public:
TPQueue() : first(0), last(0) {}
void push(T x) {
int param = last++;
while ((--param >= first) && (arr[param % size].prior <= x.prior)) {
while ((--param >= first) && (arr[param % size].prior < x.prior)) {
arr[(param + 1) % size] = arr[param % size];
}
arr[(param + 1) % size] = x;
}
T pop() {
return arr[(first++)%size];
} // реализация шаблона очереди с приоритетом на кольцевом буфере
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
