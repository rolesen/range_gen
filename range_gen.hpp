#pragma once

template<class T, class I>
struct range_gen_t {
    struct element_proxy{
        range_gen_t& ref;
        I index() const {return ref.index;}
        const T& value() const {return ref.value;}
        operator I() const {return ref.index;}
        const T& operator*() const {return ref.value;}//const: you shouldn't modify value in loop
        const T* operator->() const {return &ref.value;}//const: again, it seems wierd to modify in loop, why would you want that ?
    };
    
    range_gen_t(I i_first, I i_last, const T& _value) : index{i_first}, index_end{i_last}, value{_value} {        
    };

    auto& operator++() {
        ++index;
        ++value;
        return *this;
    }

    element_proxy operator*(){return element_proxy{*this};}

    friend bool operator!=(range_gen_t lhs, I rhs) {
        return lhs.index != rhs;
    }

    range_gen_t& begin() {return *this;}
    I end() {return index_end;}

private:       
    I index;//first element
    I index_end; //one past the last element
    T value;
};

struct range_gen_none_t {
    friend void operator++(range_gen_none_t&) {
    }
};

template<class T = range_gen_none_t, class I>
range_gen_t<T, I> range_gen(I start, I end, const T& incrementable = T{}) {
    return range_gen_t<T, I>(start, end, incrementable);
}

