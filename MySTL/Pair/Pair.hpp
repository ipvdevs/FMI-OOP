#ifndef PAIR__PAIR_HPP_
#define PAIR__PAIR_HPP_

// Read-only class
template<typename T1, typename T2>
class Pair {
 private:
  const T1 first_type;
  const T2 second_type;

 public:
  Pair(const T1& first_type, const T2& second_type);

  bool operator==(const Pair&) const;

  T1 getFirstType() const;
  T2 getSecondType() const;

  Pair<T2, T1> swapPairTypes() const;
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first_type, const T2& second_type)
    : first_type(first_type), second_type(second_type) {}

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

template<typename T1, typename T2>
Pair<T2, T1> Pair<T1, T2>::swapPairTypes() const {
  return Pair<T2, T1>(second_type, first_type);
}
#endif //PAIR__PAIR_HPP_
