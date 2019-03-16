#pragma once

#ifndef __INTERGEN_GENERATED__other_H__
#define __INTERGEN_GENERATED__other_H__

//@file Interface file for other interface generated by intergen
//See LICENSE file for copyright and license information

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include "luatest_ifc_cfg.h"
#include <comm/str.h>
namespace ns {
    class other;
    class main;
};

namespace ns1 {
    class other_cls;
}

namespace ns {

////////////////////////////////////////////////////////////////////////////////
class other
    : public intergen_interface
{
public:

    // --- interface methods ---

    const coid::charstr& get_str();

    void set_str( const coid::token& new_str );

    void some_fun1( ifc_inout int& a, ifc_inout iref<ns::other>& b, ifc_out int* c );

    // --- creators ---

    static iref<other> create( const coid::charstr& str ) {
        return create<other>(0, str);
    }

    template<class T>
    static iref<T> create( T* _subclass_, const coid::charstr& str );

    // --- internal helpers ---

    ///Interface revision hash
    static const int HASHID = 4089385363;
    
    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ns::other";
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
        static const coid::token _djs("ns::other@wrapper.js");
        static const coid::token _djsc("ns::other@wrapper.jsc");
        static const coid::token _dlua("ns::other@wrapper.lua");
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
        static_assert(std::is_base_of<other, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ns::other";
        tmp << "@client-4089385363" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    other()
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> other::create( T* _subclass_, const coid::charstr& str )
{
    typedef iref<T> (*fn_creator)(other*, const coid::charstr&);

    static fn_creator create = 0;
    static const coid::token ifckey = "ns::other.create@4089385363";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("create", "ns::other.create", "@4089385363");
        return 0;
    }

    return create(_subclass_, str);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline const coid::charstr& other::get_str()
{ return VT_CALL(const coid::charstr&,(),0)(); }

inline void other::set_str( const coid::token& new_str )
{ return VT_CALL(void,(const coid::token&),1)(new_str); }

inline void other::some_fun1( int& a, iref<ns::other>& b, int* c )
{ return VT_CALL(void,(int&,iref<ns::other>&,int*),2)(a,b,c); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__other_H__
