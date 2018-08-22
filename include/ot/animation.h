#pragma once

#ifndef __INTERGEN_GENERATED__animation_H__
#define __INTERGEN_GENERATED__animation_H__

//@file Interface file for animation interface generated by intergen
//See LICENSE file for copyright and license information

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/geom_types.h>

namespace pkg {
    class animation;
}

namespace ot {

////////////////////////////////////////////////////////////////////////////////
class animation
    : public intergen_interface
{
public:

    // --- interface methods ---

    bool is_ready() const;

    bool is_failed() const;

    int get_state() const;

    uint get_frame_count() const;

    uint get_fps() const;

    int get_frame_offset() const;

    const coid::charstr& get_filename() const;

    bool get_joint_at_time( uint geom_eid, uint joint_id, float t, ifc_out pkg::bone_data& data );

    // --- creators ---

    static iref<animation> get( const coid::token& filename, const coid::token& root, unsigned int frame_offset ) {
        return get<animation>(0, filename, root, frame_offset);
    }

    template<class T>
    static iref<T> get( T* _subclass_, const coid::token& filename, const coid::token& root, unsigned int frame_offset );

    // --- internal helpers ---

    virtual ~animation() {
        if (_cleaner) _cleaner(this,0);
    }

    ///Interface revision hash
    static const int HASHID = 2665838050;
    
    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::animation";
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
        static const coid::token _djs("ot::animation@wrapper.js");
        static const coid::token _djsc("ot::animation@wrapper.jsc");
        static const coid::token _dlua("ot::animation@wrapper.lua");
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
        static_assert(std::is_base_of<animation, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::animation";
        tmp << "@client-2665838050" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    typedef void (*cleanup_fn)(animation*, intergen_interface*);
    cleanup_fn _cleaner;

    animation() : _cleaner(0)
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> animation::get( T* _subclass_, const coid::token& filename, const coid::token& root, unsigned int frame_offset )
{
    typedef iref<T> (*fn_creator)(animation*, const coid::token&, const coid::token&, unsigned int);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::animation.get@2665838050";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get", "ot::animation.get", "@2665838050");
        return 0;
    }

    return create(_subclass_, filename, root, frame_offset);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline bool animation::is_ready() const
{ return VT_CALL(bool,() const,0)(); }

inline bool animation::is_failed() const
{ return VT_CALL(bool,() const,1)(); }

inline int animation::get_state() const
{ return VT_CALL(int,() const,2)(); }

inline uint animation::get_frame_count() const
{ return VT_CALL(uint,() const,3)(); }

inline uint animation::get_fps() const
{ return VT_CALL(uint,() const,4)(); }

inline int animation::get_frame_offset() const
{ return VT_CALL(int,() const,5)(); }

inline const coid::charstr& animation::get_filename() const
{ return VT_CALL(const coid::charstr&,() const,6)(); }

inline bool animation::get_joint_at_time( uint geom_eid, uint joint_id, float t, pkg::bone_data& data )
{ return VT_CALL(bool,(uint,uint,float,pkg::bone_data&),7)(geom_eid,joint_id,t,data); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__animation_H__
