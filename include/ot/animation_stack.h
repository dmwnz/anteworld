#pragma once

#ifndef __INTERGEN_GENERATED__animation_stack_H__
#define __INTERGEN_GENERATED__animation_stack_H__

//@file Interface file for animation_stack interface generated by intergen
//See LICENSE file for copyright and license information

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>


#include <ot/blend_tree.h>
#include <ot/geom_types.h>

namespace ot {
    class animation_stack;
    class geomob;
}

namespace pkg {
    class animation_stack;
}


namespace pkg {
    class animation_stack;
}

namespace ot {

////////////////////////////////////////////////////////////////////////////////
/// interface constructor
class animation_stack
    : public intergen_interface
{
public:

    // --- interface methods ---

    iref<ot::blend_tree> create_blend_tree( const coid::token& name );

    void blend_animation( const iref<ot::animation>& anim, float weight, bool explicit_time = false, float time = 0.f );

    ///Add animation on top of existing animations
    //@param time normalized animation time 0..1
    //@return animation id in stack
    uint add_animation( const iref<ot::animation>& anim, float time );

    //@param id animation id in stack
    //@param time normalized animation time 0..1
    void set_animation_time( uint id, float time );

    float get_animation_time( uint id );

    bool is_ready() const;

    // --- creators ---

    static iref<animation_stack> get( const iref<pkg::animation_stack>& as ) {
        return get<animation_stack>(0, as);
    }

    template<class T>
    static iref<T> get( T* _subclass_, const iref<pkg::animation_stack>& as );

    // --- internal helpers ---

    virtual ~animation_stack() {
        if (_cleaner) _cleaner(this,0);
    }

    ///Interface revision hash
    static const int HASHID = 2306565429;
    
    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::animation_stack";
        return _name;
    }

    int intergen_hash_id() const override final { return HASHID; }

    bool iface_is_derived( int hash ) const override final {
        return hash == HASHID;
    }

    const coid::tokenhash& intergen_interface_name() const override final {
        return IFCNAME();
    }

    static const coid::token& intergen_default_creator_static( EBackend bck ) {
        static const coid::token _dc("");
        static const coid::token _djs("ot::animation_stack@wrapper.js");
        static const coid::token _djsc("ot::animation_stack@wrapper.jsc");
        static const coid::token _dlua("ot::animation_stack@wrapper.lua");
        static const coid::token _dnone;

        switch(bck) {
        case IFC_BACKEND_CXX: return _dc;
        case IFC_BACKEND_JS:  return _djs;
        case IFC_BACKEND_JSC:  return _djsc;
        case IFC_BACKEND_LUA: return _dlua;
        default: return _dnone;
        }
    }


    template<enum EBackend B>
    static void* intergen_wrapper_cache() {
        static void* _cached_wrapper=0;
        if (!_cached_wrapper) {
            const coid::token& tok = intergen_default_creator_static(B);
            _cached_wrapper = coid::interface_register::get_interface_creator(tok);
        }
        return _cached_wrapper;
    }

    void* intergen_wrapper( EBackend bck ) const override final {
        switch(bck) {
        case IFC_BACKEND_JS: return intergen_wrapper_cache<IFC_BACKEND_JS>();
        case IFC_BACKEND_JSC: return intergen_wrapper_cache<IFC_BACKEND_JSC>();
        case IFC_BACKEND_LUA: return intergen_wrapper_cache<IFC_BACKEND_LUA>();
        default: return 0;
        }
    }

    EBackend intergen_backend() const override { return IFC_BACKEND_CXX; }

    const coid::token& intergen_default_creator( EBackend bck ) const override final {
        return intergen_default_creator_static(bck);
    }

    ///Client registrator
    template<class C>
    static int register_client()
    {
        static_assert(std::is_base_of<animation_stack, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::animation_stack";
        tmp << "@client-2306565429" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    typedef void (*cleanup_fn)(animation_stack*, intergen_interface*);
    cleanup_fn _cleaner;

    animation_stack() : _cleaner(0)
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> animation_stack::get( T* _subclass_, const iref<pkg::animation_stack>& as )
{
    typedef iref<T> (*fn_creator)(animation_stack*, const iref<pkg::animation_stack>&);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::animation_stack.get@2306565429";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get", "ot::animation_stack.get", "@2306565429");
        return 0;
    }

    return create(_subclass_, as);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline iref<ot::blend_tree> animation_stack::create_blend_tree( const coid::token& name )
{ return VT_CALL(iref<ot::blend_tree>,(const coid::token&),0)(name); }

inline void animation_stack::blend_animation( const iref<ot::animation>& anim, float weight, bool explicit_time, float time )
{ return VT_CALL(void,(const iref<ot::animation>&,float,bool,float),1)(anim,weight,explicit_time,time); }

inline uint animation_stack::add_animation( const iref<ot::animation>& anim, float time )
{ return VT_CALL(uint,(const iref<ot::animation>&,float),2)(anim,time); }

inline void animation_stack::set_animation_time( uint id, float time )
{ return VT_CALL(void,(uint,float),3)(id,time); }

inline float animation_stack::get_animation_time( uint id )
{ return VT_CALL(float,(uint),4)(id); }

inline bool animation_stack::is_ready() const
{ return VT_CALL(bool,() const,5)(); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__animation_stack_H__
