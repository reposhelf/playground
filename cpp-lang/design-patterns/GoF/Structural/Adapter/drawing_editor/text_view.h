#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

struct Coord {
    int value;
    Coord(int _value = 0)
        : value(_value) {}
};

class TextView {
public:
    TextView();
    
    void get_origin(Coord &x, Coord &y) const;
    void get_extent(Coord &width, Coord &height) const;
    virtual bool is_empty() const;
};

#endif
