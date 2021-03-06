/*+-------------------------------------------------------------------------+
  | hdf5_archive: a boost::serialization archive using HDF5 format          |
  | Copyright (C) 2012-2013 Daniel Koester (dk@eada.de)                     |
  |                                                                         |
  | Use, modification and distribution is subject to the Boost Software     |
  | License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at |
  | http://www.boost.org/LICENSE_1_0.txt)                                   |
  +-------------------------------------------------------------------------+*/

#ifndef HDF5_COMMON_ARCHIVE_HPP
#define HDF5_COMMON_ARCHIVE_HPP

#include <string>

namespace boost {
namespace archive {
namespace detail {

//! code common to both input and output HDF5 archive types

class hdf5_common_archive
{
protected:
    // base directory for flat data list
    static char const* const data_dir;

    // base directory for tracked object list
    static char const* const tracked_objects_dir;

    // base directory for object hierarchy tree
    static char const* const tree_dir;

    // create a path to given object dataset in the flat data list.
    std::string const create_object_data_path(std::size_t count);

    // create a path to given group in the tracked objects list.
    std::string const create_tracked_objects_path(unsigned int count);    
};

} } } // end namespace boost::archive::detail

#endif // HDF5_COMMON_ARCHIVE_HPP


