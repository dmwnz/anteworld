#pragma once

#ifndef __INTERGEN_GENERATED__blend_tree_H__
#define __INTERGEN_GENERATED__blend_tree_H__

//@file Interface file for blend_tree interface generated by intergen
//See LICENSE file for copyright and license information

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/animation.h>
#include <ot/glm/glm_meta.h>

namespace ot {
    class animation;
}

namespace pkg {
    class blend_tree;
}


namespace pkg {
    class blend_tree;
}

namespace ot {

////////////////////////////////////////////////////////////////////////////////
class blend_tree
    : public intergen_interface
{
public:

    // --- interface methods ---

    void add_node( const iref<ot::animation>& anim, const float2& pos, float time_scale );

    // --- creators ---

    static iref<blend_tree> get( const iref<pkg::blend_tree>& bt ) {
        return get<blend_tree>(0, bt);
    }

    template<class T>
    static iref<T> get( T* _subclass_, const iref<pkg::blend_tree>& bt );

    // --- internal helpers ---

    virtual ~blend_tree() {
        if (_cleaner) _cleaner(this,0);
    }

    ///Interface revision hash
    static const int HASHID = 529071738;
    
    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::blend_tree";
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
        static const coid::token _djs("ot::blend_tree@wrapper.js");
        static const coid::token _djsc("ot::blend_tree@wrapper.jsc");
        static const coid::token _dlua("ot::blend_tree@wrapper.lua");
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
        static_assert(std::is_base_of<blend_tree, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::blend_tree";
        tmp << "@client-529071738" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    typedef void (*cleanup_fn)(blend_tree*, intergen_interface*);
    cleanup_fn _cleaner;

    blend_tree() : _cleaner(0)
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> blend_tree::get( T* _subclass_, const iref<pkg::blend_tree>& bt )
{
    typedef iref<T> (*fn_creator)(blend_tree*, const iref<pkg::blend_tree>&);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::blend_tree.get@529071738";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get", "ot::blend_tree.get", "@529071738");
        return 0;
    }

    return create(_subclass_, bt);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline void blend_tree::add_node( const iref<ot::animation>& anim, const float2& pos, float time_scale )
{ return VT_CALL(void,(const iref<ot::animation>&,const float2&,float),0)(anim,pos,time_scale); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__blend_tree_H__
