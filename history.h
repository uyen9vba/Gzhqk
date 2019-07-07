#ifndef HISTORY_H
#define HISTORY_H

#endif // HISTORY_H

class History
{
public:
    virtual void fetch() = 0;
    virtual void rewind() = 0;
    virtual void commit() = 0;

};
