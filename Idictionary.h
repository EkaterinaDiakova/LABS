#ifndef IDICTIONARY_H_
#define IDICTIONARY_H_

#pragma once
template<typename TK, typename TV>
class IDictionary {
public:

    virtual bool ContainsKey(TK Key) = 0;
    virtual TV Get(TK key) = 0;
    virtual int GetSize()  = 0;
    virtual void Add(TK key, TV val) = 0;
    virtual void Print() = 0;
    virtual TK* GetKeys() = 0;
    virtual TV* GetValues() = 0;
    virtual ~IDictionary() {};
};

#endif /* IDICTIONARY_H_ */
