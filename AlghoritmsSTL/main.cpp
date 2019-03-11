#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <iterator>
#include <list>
#include <time.h>
#include <functional> //bind
#include <chrono>
#include <string>

using namespace std;


template<typename T>
void display_vector(const T & v)
{
    if (!v.size())
        return;
    cout << "\t";
    for(auto e : v)
    {
        cout.width(4);
        cout << e;
    }
    cout << endl;
}

void message(int i, const char * s)
{
    cout << i << s << endl;
}
void message(const char * s)
{
    cout << s << endl;
}

int main()
{
    int alghoritm_no = 1;
    vector <int> v1(20);
    vector <int> v2;
    list <int> list1 = {4,2,5,7,1,3,5,5};
    list <int> list2 = {2,6,9,7,4,12,5,8};
    string s {"Live as if you were to die tomorrow. Learn as if you were to live forever."};
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen1(seed);
    mt19937 gen2(seed+5);
    uniform_int_distribution<std::mt19937::result_type> dist(1,20);


    message("This is a presentation of most STL algorithms in c++ for my training purposes.");
    message("------------------------------------------------------------------------------");
    message("Version 1 completed till algorithm no 45.");
    message("\nLet's start with populating vectors.\n");

    message(alghoritm_no++, ". Generate algorithm");
    message("\tVector 1:");
    generate(begin(v1), end(v1), bind(dist, gen1));
    display_vector(v1);

    message(alghoritm_no++, ". and Generate_n algorithm");
    message("\tVector 2:");
    generate_n(back_inserter(v2), 20, bind(dist, gen2));
    display_vector(v2);


    message("\nGroup one: Non-modifying sequence operations: ");
    message("--------------------------------------------- ");

    message(alghoritm_no++, ". all_of. Let's check if all numbers of vector one are odd");
    if(all_of(begin(v1), end(v1), [](int i)
{
    return i &1;
}))
    message("\tAll numbers are odd");
    else
        message("\tAt least one number is not odd");

    message(alghoritm_no++, ". any_of. Let's check if at least one number of vector one is odd");
    if(any_of(begin(v1), end(v1), [](int i)
{
    return i &1;
}))
    message("\tAt least one number is odd");
    else
        message("\tAll of the numbers are not odd");

    message(alghoritm_no++, ". none_of. Let's check if not a single number of vector one is odd");
    if(none_of(begin(v1), end(v1), [](int i)
{
    return i &1;
}))
    message("\tThere is not a single number that is odd");
    else
        message("\tAt least one number is odd");

    message(alghoritm_no++, ". for_each. A function that can do almost everything. So let's add 3 to every element of vector one.");
    for_each(begin(v1),end(v1), [](int &i)
    {
        i +=3;
    });
    display_vector(v1);
    for_each(begin(v1),end(v1), [](int &i)
    {
        i -=3;
    });

    message(alghoritm_no++, ". count. Let's check how many times 5 is in list 1");
    display_vector(list1);
    cout << "\tNumber 5 is " << count(begin(list1), end(list1), 5) << " times in list one."<<endl;

    message(alghoritm_no++, ". count_if. Let's count odd numbers in list one");
    cout << "\tThere are " << count_if(begin(list1), end(list1), [](int i)
    {
        return i%2==1;
    }) << " odd numbers."<<endl;

    message(alghoritm_no++, ". sort. Let's sort list one:");
    display_vector(list1);
    list1.sort();
    message("\tSorted list:");
    display_vector(list1);

    message(alghoritm_no++, ". transform. An algorithm from second group. Will convert letter so small case in the following sentence:");
    string palindrome {"A man a plan a Canal Panama"};
    cout << "\tOryginal sentence: " << palindrome <<endl;
    string palindomeCopy = palindrome;
    transform(begin(palindomeCopy), end(palindomeCopy), begin(palindomeCopy), ::tolower);
    cout << "\tSmall case sentence: " << palindomeCopy <<endl;

    message(alghoritm_no++, ". remove_if with erase. An algorithm from second group. Let's remove all white spaces");
    palindomeCopy.erase(remove_if(begin(palindomeCopy), end(palindomeCopy), ::isspace), end(palindomeCopy));
    cout << "\tWithout white spaces sentence: " << palindomeCopy <<endl;

    message(alghoritm_no++, ". mismatch. Let's check if a sentence \"A man a plan a Canal Panama\" is a palindrome.");
    auto it3 = mismatch(begin(palindomeCopy), end(palindomeCopy),rbegin(palindomeCopy));
    string is {(it3.first == end(palindomeCopy) && it3.second == rend(palindomeCopy)) ? " is" : " isn't"};
    cout << "\tThe sentence :" << palindrome << is << " a palindorme."<<endl;

    message(alghoritm_no++, ". find. Let's check if list one contain number 5.");
    if ( find(begin(list1), end(list1), 5) != end(list1))
        message("\tList one contains number 5.");
    else
        message("\tVector one does not contains number 5.");

    message(alghoritm_no++, ". find_if. Let's find if list one contain a number bigger than 5 and which one is it:");
    auto it1 = find_if(begin(list1), end(list1), [](const auto& item)
    {
        return item > 5;
    });
    if (it1 != end(list1))
        cout << "\tFound following number bigger than 5: " << *it1 << endl;
    else
        message("No number bigger than 5 was found in list one");

    message(alghoritm_no++, ". adjacent_find. Let's check if list one is sorted in non-decreasing order");
    display_vector(list1);
    string is1 = (adjacent_find(begin(list1), end(list1), greater<int>()) == end(list1))? "is":"isn't";
    cout << "\tThe list one " << is1 <<" sorted in non-decreasing order." << endl;

    message(alghoritm_no++, ". search. Let's find the first position of word \"you\" in the following string: ");
    cout << "\t" << s << endl;
    string to_find{"you"};
    auto it2 = search(begin(s), end(s), begin(to_find), end(to_find));
    cout << "\tThe first occurrence of word \"you\" was found at the position: " << distance(begin(s), it2) << endl;

    message(alghoritm_no++, ". find_end.  Let's find the last position of word \"you\" in the following string: ");
    cout << "\t" << s << endl;
    it2 = find_end(begin(s), end(s), begin(to_find), end(to_find));
    cout << "\tThe last occurrence word \"you\" was found at the position: " << distance(begin(s), it2) << endl;

    message(alghoritm_no++, ". find_first_of. Find first vowel in the following sentence:");
    cout << "\t" << s << endl;
    string vowels{"aeiou"};
    it2 = find_first_of(begin(s), end(s), begin(vowels), end(vowels));
    cout << "\tThe firs vowel was found at the position: " << distance(begin(s), it2) << endl;

    message("\nGroup two: Modifying sequence operations: ");
    message("----------------------------------------- ");

    message(alghoritm_no++, ". copy. Let's print vector one:");
    cout << "\t";
    copy(begin(v1), end(v1), ostream_iterator<int>(cout, " | "));
    cout << endl;

    message(alghoritm_no++, ". copy_if.  Let's print only odd numbers from vector one");
    cout << "\t";
    copy_if(begin(v1), end(v1), ostream_iterator<int>(cout, " "), [](const auto item)
    {
        return item &1;
    });
    message("");

    message(alghoritm_no++, ". move. Move the first element of vector 1:");
    display_vector(v1);
    message("\tto vector 2:");
    display_vector(v2);
    move(begin(v1), begin(v1)+1, begin(v2));
    message("\tVectors after moving:");
    display_vector(v1);
    display_vector(v2);

    message(alghoritm_no++, ". fill. Let's fill vector one with five fives at the beginning:");
    fill(begin(v1), begin(v1)+5, 5);
    display_vector(v1);

    message(alghoritm_no++, ". generate. Let's make a Fibonacci Sequence: ");
    vector <int> v4;
    generate_n(back_inserter(v4), 10, [i = 0, j = 1]()mutable { j = exchange(i, i+j); return i; });
    display_vector(v4);

    message(alghoritm_no++, ". replace. Let's replace all occurrences of 5 with 10 in list one.");
    display_vector(list1);
    replace(begin(list1), end(list1), 5, 10);
    display_vector(list1);

    message(alghoritm_no++, ". swap. Let's swap first and last element of vector one.");
    display_vector(v1);
    swap(v1[0], v1[v1.size()-1]);
    display_vector(v1);

    message(alghoritm_no++, ". swap_ranges. Let's reverse a sentence: \"So many books, so little time.\"");
    string zappa{"So many books, so little time."};
    swap_ranges(begin(zappa), next(begin(zappa), zappa.size()/2), rbegin(zappa));
    cout<< "\tReversed sentence: " << zappa << endl;

    message(alghoritm_no++, ". reverse. And back!");
    reverse(begin(zappa), end(zappa));
    cout<< "\tReversed back sentence: " << zappa << endl;

    message(alghoritm_no++, ". reverse_copy. Let's reverse vector one:");
    display_vector(v1);
    vector<int> v5;
    reverse_copy(begin(v1), end(v1), back_inserter(v5));
    message("\tAfter reversing:");
    display_vector(v5);

    message(alghoritm_no++, ". iter_swap. Let's do selection sort on vector one.");
    display_vector(v1);
    for(auto i = begin(v1); i!= end(v1); ++i)
        iter_swap(i, min_element(i, end(v1)));
    display_vector(v1);

    message(alghoritm_no++, ". rotate. Let's do insertion sort on vector two.");
    display_vector(v2);
    for(auto i = begin(v2); i!= end(v2); ++i)
        rotate(upper_bound(begin(v2), i, *i), i, i+1);
    display_vector(v2);

    message(alghoritm_no++, ". shuffle. And now let's unsort vector one.");
    shuffle(begin(v1), end(v1), gen1);
    display_vector(v1);

    message(alghoritm_no++, ". unique. Let's remove duplicated in list one:");
    display_vector(list1);
    list<int> list3  = list1;
    list3.erase((unique(begin(list3), end(list3))),end(list3));
    message("After removing:");
    display_vector(list3);

    message("\nGroup three: Partitioning operations: ");
    message("------------------------------------- ");

    message(alghoritm_no++, ". is_partitioned. Let's check if vector one is partitioned for even and odd numbers");
    auto is_even = [](int i)
    {
        return i % 2 == 0;
    };
    string isP = is_partitioned(v1.begin(), v1.end(), is_even) ? "is":"isn't";
    cout << "\tVector one " << isP <<  " partitioned for even and odd numbers" << endl;

    message(alghoritm_no++, ". partition. Let's partition copy of vector one for even and odd numbers...");
    vector<int> v7 = v1;
    partition(v7.begin(), v7.end(), is_even);
    display_vector(v7);

    message("\t...and check if the copy is_partitioned.");
    isP = is_partitioned(v7.begin(), v7.end(), is_even) ? "is":"isn't";
    cout << "\tCopy of vector one " << isP <<  " partitioned for even and odd numbers" << endl;
    message(alghoritm_no++, ". stable_partition. Now let's keep the order of elements in referenece to each other");
    v7 = v1;
    stable_partition(v7.begin(), v7.end(), is_even);
    display_vector(v7);

    message(alghoritm_no++, ". partition_point. And the partition point is behind the...");
    cout << "\t"<<distance(v7.begin(), partition_point(v7.begin(), v7.end(), is_even))<<"th element" <<endl;


    message("\nGroup four: Sorting operations: ");
    message("------------------------------- ");

    message(alghoritm_no++, ". is_sorted. Let's check if vector 1 and 2 are sorted.");
    string s1 = is_sorted(begin(v1), end(v1))?"is":"isn't";
    string s2 = is_sorted(begin(v2), end(v2))?"is":"isn't";
    cout << "\tVector one " << s1<< " sorted and vector two "<< s2 << " sorted."<<endl;

    message(alghoritm_no++, ". partial_sort. Let's sort first half of elements of vector one.");
    message("\tBefore sorting:");
    display_vector(v1);
    partial_sort(v1.begin(), v1.begin() + v1.size()/2, v1.end());
    message("\tAfter sorting:");
    display_vector(v1);

    message(alghoritm_no++, ". is_sorted_until. And now let's check if partial sorting worked well.");
    cout << "\tVector is sorted until " << distance( begin(v1), is_sorted_until(begin(v1), end(v1))) <<" th position." << endl;

    message(alghoritm_no++, ". nth_element. Let's find a median of vector one.");
    nth_element(v1.begin(), v1.begin() + v1.size()/2, v1.end());
    cout << "\tThe median is " << v1[v1.size()/2] << endl;

    message("\nGroup five: Binary search operations (on sorted ranges): ");
    message("-------------------------------------------------------- ");
    sort(begin(v1), end(v1));

    message(alghoritm_no++, ". lower_bound. Let's find where passage with number 5 starts in vector one...");
    display_vector(v1);
    cout << "\tA passage with number 5 starts at the position: " << distance(begin(v1), lower_bound(v1.begin(), v1.end(),5)) << endl;

    message(alghoritm_no++, ". upper_bound. ... and where it ends.");
    cout << "\tA passage with number 5 ends at the position: " << distance(begin(v1), upper_bound(v1.begin(), v1.end(),5))-1 << endl;

    message(alghoritm_no++, ". equal_range. And the same but at once:");
    auto p = equal_range(begin(v1), end(v1), 5);
    cout << "\tA passage with number 5 starts at the position: " << distance(begin(v1), p.first) << " and ends at position: " << distance(begin(v1), p.second)-1 <<endl;
    message(alghoritm_no++, ". binary_search. Let's check if vector 1 contains number 10.");
    string cont = binary_search(begin(v1), end(v1), 10)?"does":"doesn't";
    cout << "\tVector one "<< cont << " contain number 10."<<endl;

    message("\nGroup six: Other operations on sorted ranges: ");
    message("--------------------------------------------- ");

    message(alghoritm_no++, ". merge. Let's merge list 2:");

    display_vector(list2);
    message("\twith list 1:");
    list1.sort();
    list2.sort();
    display_vector(list1);
    list2.merge(list1);
    display_vector(list2);

    message("\nGroup seven: Set operations (on sorted ranges): ");
    message("----------------------------------------------- ");
    message(alghoritm_no++, ". includes");
    message(alghoritm_no++, ". set_difference");
    message(alghoritm_no++, ". set_intersection");
    message(alghoritm_no++, ". set_symmetric_difference");
    message(alghoritm_no++, ". set_union");
    message("\nGroup eight: Heap operations: ");
    message("----------------------------- ");
    message(alghoritm_no++, ". make_heap");
    message(alghoritm_no++, ". push_heap");
    message(alghoritm_no++, ". pop_heap");
    message(alghoritm_no++, ". sort_heap");
    message(alghoritm_no++, ". is_heap");
    message(alghoritm_no++, ". is_heap_until");
    message("\nGroup nine: Minimum/maximum operations: ");
    message("--------------------------------------- ");
    message(alghoritm_no++, ". max");
    message(alghoritm_no++, ". max_element");
    message(alghoritm_no++, ". min");
    message(alghoritm_no++, ". minmax");
    message(alghoritm_no++, ". clamp");
    message("\nGroup ten: Comparison operations: ");
    message("--------------------------------- ");
    message(alghoritm_no++, ". equal");
    message(alghoritm_no++, ". lexicographical_compare");
    message("\nGroup eleven: Permutation operations: ");
    message("------------------------------------- ");
    message(alghoritm_no++, ". is_permutation");
    message(alghoritm_no++, ". next_permutation");
    message(alghoritm_no++, ". prev_permutation");
    message("\nGroup twelve: Numeric operations: ");
    message("--------------------------------- ");

    message(alghoritm_no++, ". iota. Let's create a new vector and fill it with values incremented by 1:");
    vector <int> v3(5);
    iota(begin(v3), end(v3), 1);
    display_vector(v3);

    message(alghoritm_no++, ". accumulate. Let's now multiply all the elements of just created vector:");
    long long acc = accumulate(begin(v3), end(v3), 1, multiplies<int> {});
    cout << "\tThe result is: " << acc << endl;

    message(alghoritm_no++, ". inner_product");
    message(alghoritm_no++, ". adjacent_difference");
    message(alghoritm_no++, ". partial_sum");
    message(alghoritm_no++, ". reduce");
    message(alghoritm_no++, ". exclusive_scan");
    message(alghoritm_no++, ". inclusive_scan");
    message(alghoritm_no++, ". transform_reduce");
    message(alghoritm_no++, ". transform_exclusive_scan");
    message(alghoritm_no++, ". transform_inclusive_scan");
    return 0;
}
