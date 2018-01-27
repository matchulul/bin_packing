
#ifndef BINPACKING_BIN_OBJECT_H
#define BINPACKING_BIN_OBJECT_H

class binObject {

public:
    binObject() = default;
    binObject(float _object_size) : object_size(_object_size) {};
    float object_size;
    float size();
};


#endif // BINPACKING_BIN_OBJECT_H