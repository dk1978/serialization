/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_xml_iarchive.ipp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . Permission to copy, 
// use, modify, sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided "as is"
// without express or ied warranty, and with no claim as to its suitability
// for any purpose.

//  See http://www.boost.org for updates, documentation, and revision history.

#include <cassert>
#include <algorithm>

#include <boost/throw_exception.hpp>

#include <boost/serialization/tracking.hpp>
#include <boost/archive/basic_xml_iarchive.hpp>

namespace boost {
namespace archive {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// implementation of xml_text_archive

template<class Archive>
void basic_xml_iarchive<Archive>::load_start(const char *name){
    // if there's no name
    if(NULL == name)
        return;
    bool result = this->This()->gimpl->parse_start_tag(this->This()->get_is());
    if(true != result){
        boost::throw_exception(
            archive_exception(archive_exception::stream_error)
        );
    }
    // don't check start tag at highest level
    ++depth;
    return;
}

template<class Archive>
void basic_xml_iarchive<Archive>::load_end(const char *name){
    // if there's no name
    if(NULL == name)
        return;
    bool result = this->This()->gimpl->parse_end_tag(this->This()->get_is());
    if(true != result){
        boost::throw_exception(
            archive_exception(archive_exception::stream_error)
        );
    }
    
    // don't check start tag at highest level
    if(0 == --depth)
        return;
        
    if(! no_checking){
        // double check that the tag matches what is expected - useful for debug
        if(0 != name[this->This()->gimpl->rv.object_name.size()]
        || ! std::equal(
                this->This()->gimpl->rv.object_name.begin(),
                this->This()->gimpl->rv.object_name.end(),
                name
            )
        ){
            boost::throw_exception(
                archive_exception(archive_exception::stream_error)
            );
        }
    }
}

template<class Archive>
void basic_xml_iarchive<Archive>::load_override(object_id_type & t, int){
    t = this->This()->gimpl->rv.object_id;
}

template<class Archive>
void basic_xml_iarchive<Archive>::load_override(version_type & t, int){
    t = this->This()->gimpl->rv.version;
}

template<class Archive>
void basic_xml_iarchive<Archive>::load_override(class_id_type & t, int){
    t = this->This()->gimpl->rv.class_id;
}

template<class Archive>
void basic_xml_iarchive<Archive>::load_override(tracking_type & t, int){
    t = this->This()->gimpl->rv.tracking_level;
}

} // namespace archive
} // namespace boost
