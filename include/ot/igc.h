#pragma once

#ifndef _INTERGEN_GENERATED__igc_H_
#define _INTERGEN_GENERATED__igc_H_

//@file Interface file for igc interface generated by intergen
//See LICENSE file for copyright and license information

//host class: ::app

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/glm/glm_meta.h>

#include <ot/igc_data.h>

class app;


namespace ot {

////////////////////////////////////////////////////////////////////////////////
///OT IGC (image generator control) interface //////////////////////////////
class igc
    : public intergen_interface
{
public:

    // --- interface methods ---

    ///Set camera position
    //@param ecef position in ECEF coordinates
    //@param rot camera rotation into OT view space (-z forward, +y up, +x side)
    void set_pos( const double3& ecef, const quat& rot );

    ///Get current camera position in ECEF
    const double3& pos();

    ///Get current camera rotation in OT view space (-z forward, +y up, +x side)
    const quat& rot();

    ///Get info about current position & speed
    void info( ifc_out ot::igc_data& data );

    ///Test intesection of ray with terrain
    //@return >= 0 intersection distance, <0 for no intersect
    //@param from starting position of the ray to test
    //@param to ending position of the ray to test, note: keep the ray as short as possible
    //@param pos surface position at the intersecting point
    //@param norm surface normal at the intersection
    //@param dist distance from the starting point to intersection
    double intersect( const double3& from, const double3& to, ifc_out double3& pos, ifc_out float3& norm );

    ///Set world time for current location
    //@param dyear day of year
    //@param tday solar time of day
    //@param flowm time flow multiplier, 1.0 normal time flow
    void set_time( int64 dyear, double tday, float flowm = 1.0f );


protected:
    // --- interface events (callbacks from host to client) ---
    // ---       overload these to handle host events       ---

    friend class ::app;

    ///Event invoked before rendering frame
    //@param time the current game time for the frame
    virtual void update( double time ) {}

    virtual void force_bind_script_events() {}

public:
    // --- host helpers to check presence of handlers in scripts ---

    virtual bool is_bound_update() { return true; }

public:
    // --- creators ---

    static iref<igc> get() {
        return get<igc>(0);
    }

    template<class T>
    static iref<T> get( T* _subclass_ );

    // --- internal helpers ---

    virtual ~igc() {
        if (_cleaner)
            _cleaner(this, 0);
    }

    ///Interface revision hash
    static const int HASHID = 3956023360u;

    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::igc"_T;
        return _name;
    }

    int intergen_hash_id() const override final { return HASHID; }

    bool iface_is_derived( int hash ) const override final {
        return hash == HASHID;
    }

    const coid::tokenhash& intergen_interface_name() const override final {
        return IFCNAME();
    }

    static const coid::token& intergen_default_creator_static( backend bck ) {
        static constexpr coid::token _dc("ot::igc.get@3956023360"_T);
        static constexpr coid::token _djs("ot::igc@wrapper.js"_T);
        static constexpr coid::token _djsc("ot::igc@wrapper.jsc"_T);
        static constexpr coid::token _dlua("ot::igc@wrapper.lua"_T);
        static constexpr coid::token _dnone;

        switch(bck) {
        case backend::cxx: return _dc;
        case backend::js:  return _djs;
        case backend::jsc: return _djsc;
        case backend::lua: return _dlua;
        default: return _dnone;
        }
    }

    //@return cached active interface of given host class
    //@note host side helper
    static iref<igc> intergen_active_interface(::app* host);

    template<enum class backend B>
    static void* intergen_wrapper_cache() {
        static void* _cached_wrapper=0;
        if (!_cached_wrapper) {
            const coid::token& tok = intergen_default_creator_static(B);
            _cached_wrapper = coid::interface_register::get_interface_creator(tok);
        }
        return _cached_wrapper;
    }

    void* intergen_wrapper( backend bck ) const override final {
        switch(bck) {
        case backend::js:  return intergen_wrapper_cache<backend::js>();
        case backend::jsc: return intergen_wrapper_cache<backend::jsc>();
        case backend::lua: return intergen_wrapper_cache<backend::lua>();
        default: return 0;
        }
    }

    backend intergen_backend() const override { return backend::cxx; }

    const coid::token& intergen_default_creator( backend bck ) const override final {
        return intergen_default_creator_static(bck);
    }

    ///Client registrator
    template<class C>
    static int register_client()
    {
        static_assert(std::is_base_of<igc, C>::value, "not a base class");

        typedef intergen_interface* (*fn_client)();
        fn_client cc = []() -> intergen_interface* { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::igc"_T;
        tmp << "@client-3956023360"_T << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    static coid::comm_mutex& share_lock() {
        static coid::comm_mutex _mx(500, false);
        return _mx;
    }

    ///Cleanup routine called from ~igc()
    static void _cleaner_callback(igc* m, intergen_interface* ifc) {
        m->assign_safe(ifc, 0);
    }

    bool assign_safe(intergen_interface* client__, iref<igc>* pout);

    typedef void (*cleanup_fn)(igc*, intergen_interface*);
    cleanup_fn _cleaner = 0;

    bool set_host(policy_intrusive_base*, intergen_interface*, iref<igc>* pout);
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> igc::get( T* _subclass_ )
{
    typedef iref<T> (*fn_creator)(igc*);

    static fn_creator create = 0;
    static constexpr coid::token ifckey = "ot::igc.get@3956023360"_T;

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get"_T, "ot::igc.get"_T, "@3956023360"_T);
        return 0;
    }

    return create(_subclass_);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline void igc::set_pos( const double3& ecef, const quat& rot )
{ return VT_CALL(void,(const double3&,const quat&),0)(ecef,rot); }

inline const double3& igc::pos()
{ return VT_CALL(const double3&,(),1)(); }

inline const quat& igc::rot()
{ return VT_CALL(const quat&,(),2)(); }

inline void igc::info( ot::igc_data& data )
{ return VT_CALL(void,(ot::igc_data&),3)(data); }

inline double igc::intersect( const double3& from, const double3& to, double3& pos, float3& norm )
{ return VT_CALL(double,(const double3&,const double3&,double3&,float3&),4)(from,to,pos,norm); }

inline void igc::set_time( int64 dyear, double tday, float flowm )
{ return VT_CALL(void,(int64,double,float),5)(dyear,tday,flowm); }

#pragma warning(pop)

} //namespace

#endif //_INTERGEN_GENERATED__igc_H_
