#### Redis中hyperloglog是用来做基数统计
#### 1.主要原理
Hyperloglog结构中，redis定义桶个数(16384)，index所在低[log2(16384)]14位为桶索引,从第14位开始第一次出现“1”的位置为注册值。  
注册值只有50个数，50个可以用[log2(50)]6个bit就能保存.  
以下例hashCode为例：
```
 64                                           14            1
+----------------------------------------------+--------------+
|0000000000000000000000000000000000000000000100|00000000000001|
+----------------------------------------------+--------------+
低位桶索引为:1，注册值为4。
```
#### 2.主要代码
##### 2.1 数据结构
```c++
struct hllhdr {
    char magic[4];      // 固定‘HYLL’，用于标识hyperloglog键
    uint8_t encoding;   // 编码模式，有密集标识Dence和稀疏模式sparse
    uint8_t notused[3]; // 未使用字段，留着日后用
    uint8_t card[8];    // 基数缓存，存储上一次计算的基数
    uint8_t registers[]; // 桶个数，用来存放数据，Redis中大小为16384
};
```
