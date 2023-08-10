#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // 双向链表，存储键值对
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // 哈希表，存储键对应的链表迭代器

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            // 如果key不存在于缓存中，返回-1
            return -1;
        } else {
            // 如果key存在于缓存中，将其移到链表头部，并返回值
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList, it);
            return it->second;
        }
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // 如果key已经存在于缓存中，更新其值，并将其移到链表头部
            auto it = cacheMap[key];
            it->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it);
        } else {
            // 如果key不存在于缓存中
            if (cacheList.size() >= capacity) {
                // 如果缓存已满，删除链表尾部元素和哈希表对应项
                int lastKey = cacheList.back().first;
                cacheMap.erase(lastKey);
                cacheList.pop_back();
            }
            // 在链表头部插入新键值对，并在哈希表中存储对应迭代器
            cacheList.push_front(make_pair(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    LRUCache cache(3); // 创建容量为3的LRU缓存

    cache.put(1, 100); // 缓存中：(1, 100)
    cache.put(2, 200); // 缓存中：(2, 200) -> (1, 100)
    cache.put(3, 300); // 缓存中：(3, 300) -> (2, 200) -> (1, 100)

    cout << cache.get(2) << endl; // 输出200，缓存中：(2, 200) -> (3, 300) -> (1, 100)

    cache.put(4, 400); // 缓存已满，删除最近最少使用的元素(1, 100)，缓存中：(4, 400) -> (2, 200) -> (3, 300)

    cout << cache.get(1) << endl; // 输出-1，因为1已经被淘汰出缓存

    return 0;
}
