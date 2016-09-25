template<class RanIt, class Comparator>
void mergesort(const RanIt begin, const RanIt end, Comparator cmp)
{
    auto size = std::distance(begin, end);
    if (size < 2)
        return;

    auto mid = std::next(begin, size / 2);
    mergesort(begin, mid, cmp);
    mergesort(mid, end, cmp);
    vector<typename RanIt::value_type> merged;
    RanIt a{begin}, b{mid};
    while(a!=mid&&b!=end){
      merged.push_back((*cmp)(*a,*b)?move(*a++):move(*b++));
    }
    merged.insert(merged.end(), a, mid);
    merged.insert(merged.end(), b, end);
    move(merged.cbegin(), merged.cend(), begin);
}
