#pragma once

#ifndef __INTERGEN_GENERATED__fb_H__
#define __INTERGEN_GENERATED__fb_H__

//@file Interface file for fb interface generated by intergen
//See LICENSE file for copyright and license information

//host class: ::framebuffer

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/location_cfg.h>
#include <ot/sdm_types.h>

class framebuffer;


namespace ot {

////////////////////////////////////////////////////////////////////////////////

class fb
    : public intergen_interface
{
public:

    // --- interface methods ---

    void nvg_enable( bool enable );

    bool is_nvg_enabled() const;

    
    void set_nvg_params( float contrast, float amplify, float noise );

    void set_nvg_color( const float3& color );

    void ir_enable( bool enable );

    bool is_ir_enabled() const;

    
    void set_ir_params( float contrast, float amplify, float noise, float focus );

    ///
    void set_sdm_mesh( const ot::sdm_vertex* ptr, uint nvertices, const uint* indices, uint nindices, const float2& fov );

    void set_max_bloom_level( uint lev );

    // --- creators ---

    static iref<fb> get() {
        return get<fb>(0);
    }

    template<class T>
    static iref<T> get( T* _subclass_ );

    // --- internal helpers ---

    virtual ~fb() {
        if (_cleaner)
            _cleaner(this, 0);
    }

    ///Interface revision hash
    static const int HASHID = 541474843;

    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::fb";
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
        static const coid::token _dc("ot::fb.get@541474843");
        static const coid::token _djs("ot::fb@wrapper.js");
        static const coid::token _djsc("ot::fb@wrapper.jsc");
        static const coid::token _dlua("ot::fb@wrapper.lua");
        static const coid::token _dnone;

        switch(bck) {
        case IFC_BACKEND_CXX: return _dc;
        case IFC_BACKEND_JS:  return _djs;
        case IFC_BACKEND_JSC:  return _djsc;
        case IFC_BACKEND_LUA: return _dlua;
        default: return _dnone;
        }
    }

    //@return cached active interface of given host class
    //@note host side helper
    static iref<fb> intergen_active_interface(::framebuffer* host);

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
        static_assert(std::is_base_of<fb, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::fb";
        tmp << "@client-541474843" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    static coid::comm_mutex& share_lock() {
        static coid::comm_mutex _mx(500, false);
        return _mx;
    }

    typedef void (*cleanup_fn)(fb*, intergen_interface*);
    cleanup_fn _cleaner;

    fb() : _cleaner(0)
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> fb::get( T* _subclass_ )
{
    typedef iref<T> (*fn_creator)(fb*);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::fb.get@541474843";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get", "ot::fb.get", "@541474843");
        return 0;
    }

    return create(_subclass_);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline void fb::nvg_enable( bool enable )
{ return VT_CALL(void,(bool),0)(enable); }

inline bool fb::is_nvg_enabled() const
{ return VT_CALL(bool,() const,1)(); }

inline void fb::set_nvg_params( float contrast, float amplify, float noise )
{ return VT_CALL(void,(float,float,float),2)(contrast,amplify,noise); }

inline void fb::set_nvg_color( const float3& color )
{ return VT_CALL(void,(const float3&),3)(color); }

inline void fb::ir_enable( bool enable )
{ return VT_CALL(void,(bool),4)(enable); }

inline bool fb::is_ir_enabled() const
{ return VT_CALL(bool,() const,5)(); }

inline void fb::set_ir_params( float contrast, float amplify, float noise, float focus )
{ return VT_CALL(void,(float,float,float,float),6)(contrast,amplify,noise,focus); }

inline void fb::set_sdm_mesh( const ot::sdm_vertex* ptr, uint nvertices, const uint* indices, uint nindices, const float2& fov )
{ return VT_CALL(void,(const ot::sdm_vertex*,uint,const uint*,uint,const float2&),7)(ptr,nvertices,indices,nindices,fov); }

inline void fb::set_max_bloom_level( uint lev )
{ return VT_CALL(void,(uint),8)(lev); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__fb_H__
