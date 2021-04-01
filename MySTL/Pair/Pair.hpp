#ifndef PAIR__PAIR_HPP_
#define PAIR__PAIR_HPP_

// Class Pair must be read-only
template<typename T1, typename T2>
class Pair {
 private:
  T1 first_type;
  T2 second_type;

 public:
  Pair(const T1& first_type, const T2& second_type);

  Pair<T1, T2>& operator=(const Pair&);
  bool operator==(const Pair&) const;
  // TODO SWAP

  T1 getFirstType() const;
  T2 getSecondType() const;

};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first_type, const T2& second_type) {
  this->first_type = first_type;
  this->second_type = second_type;
}

template<typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair& other) {
  if (this != &other) {
    this->first_type = other.first_type;
    this->second_type = other.second_type;
  }

  return *this;
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator==(const Pair& other) const {
  return this->first_type == other.first_type
      && this->second_type == other.second_type;
}

template<typename T1, typename T2>
T1 Pair<T1, T2>::getFirstType() const {
  return this->first_type;
}

template<typename T1, typename T2>
T2 Pair<T1, T2>::getSecondType() const {
  return this->second_type;
}

#endif //PAIR__PAIR_HPP_
