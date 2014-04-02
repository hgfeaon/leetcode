#include <iostream>
#include <cstdlib>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache{
private:
    int max_size;
    unordered_map<int, list<pair<int, int> >::iterator> hash;
    list<pair<int, int> > lru_stack;
public:
    LRUCache(int capacity) {
        if (capacity < 1) capacity = 0;
        max_size = capacity;
    }

    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator miter = hash.find(key);
        list<pair<int, int> >::iterator liter;
        if (miter == hash.end()) {
            return -1;
        } else {
            liter = miter->second;
            int val = liter->second;
            lru_stack.erase(liter);
            miter->second = liter = lru_stack.insert(lru_stack.begin(), make_pair(key, val));
            return liter->second;
        }
    }

    void set(int key, int value) {
        if (max_size == 0) return;
        unordered_map<int, list<pair<int, int> >::iterator>::iterator miter = hash.find(key);
        list<pair<int, int> >::iterator liter;
        if (miter == hash.end()) {   // key not exists in the cache
            if (hash.size() == max_size) {
                // invalidate LRU item to avoid overflow
                hash.erase(lru_stack.back().first);
                lru_stack.pop_back();
            }
            liter = lru_stack.insert(lru_stack.begin(), make_pair(key, value));
            hash.insert(make_pair(key, liter));
        } else {    // key already exists, so replace the value with new one
            liter = miter->second;
            lru_stack.erase(liter);
            miter->second = lru_stack.insert(lru_stack.begin(), make_pair(key, value));
        }
    }
};

int main() {
    LRUCache cache(4);
    cache.set(1, 100);
    cache.set(2, 200);
    cache.set(3, 300);
    cache.set(4, 400);
    cache.get(1);
    cache.get(2);
    cache.set(5, 500);
    
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    cout<<cache.get(5)<<endl;
    cout<<cache.get(4)<<endl;
    
	system("pause");
	return 0;
}

