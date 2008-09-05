#ifndef RBX_BUILTIN_TUPLE_HPP
#define RBX_BUILTIN_TUPLE_HPP

#include "builtin/object.hpp"
#include "type_info.hpp"

namespace rubinius {
  class Tuple : public Object {
  public:
    const static size_t fields = 0;
    const static object_type type = TupleType;

    static Tuple* create(STATE, size_t fields);
    static Tuple* from(STATE, size_t fields, ...);

    // Ruby.primitive :tuple_allocate
    static Tuple* allocate(STATE, FIXNUM fields);

    OBJECT at(size_t index);

    // Ruby.primitive :tuple_at
    OBJECT at_prim(STATE, FIXNUM pos);

    OBJECT put(STATE, size_t idx, OBJECT val);

    // Ruby.primitive :tuple_put
    OBJECT put_prim(STATE, FIXNUM idx, OBJECT val);

    // Ruby.primitive :tuple_fields
    OBJECT fields_prim(STATE);

    // Ruby.primitive :tuple_copy_from
    Tuple* copy_from(STATE, Tuple* other, FIXNUM start, FIXNUM dest);

    // Ruby.primitive :tuple_shifted
    Tuple* shifted(STATE, FIXNUM num);

    // Ruby.primitive :tuple_create_weakref
    static Tuple* create_weakref(STATE, OBJECT obj);

    void replace_with(STATE, Tuple* other, int start, int end);

    class Info : public TypeInfo {
    public:
      Info(object_type type) : TypeInfo(type) { }
      virtual void mark(OBJECT t, ObjectMark& mark);
      virtual void show(STATE, OBJECT self, int level);
      virtual void show_simple(STATE, OBJECT self, int level);
    };
  };
};

#endif
