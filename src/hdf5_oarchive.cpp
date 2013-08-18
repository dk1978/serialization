/*+-------------------------------------------------------------------------+
  | hdf5_archive: a boost::serialization archive using HDF5 format          |
  | Copyright (C) 2012-2013 Daniel Koester (dk@eada.de)                     |
  +-------------------------------------------------------------------------+*/

#include "archive/hdf5_oarchive.hpp"
#include <boost/archive/detail/archive_serializer_map.hpp>

// explicitly instantiate for this type of archive
#include <boost/archive/impl/archive_serializer_map.ipp>
#include "archive/impl/hdf5_oarchive_impl.ipp"

namespace boost {
namespace archive {

template class detail::archive_serializer_map< ::archive::hdf5_oarchive>;

} // namespace archive
} // namespace boost

namespace archive {

// explicit instantiation of the implementation:
template class hdf5_oarchive_impl<hdf5_oarchive> ;

} // namespace archive
