/**
 * \file DatabaseRetrievalAlg.h
 *
 * \ingroup WebDBI
 *
 * \brief Class def header for a class DatabaseRetrievalAlg
 *
 * @author kterao, eberly@slac.stanford.edu
 */

/** \addtogroup WebDBI

    @{*/
#ifndef DATABASERETRIEVALALG_H
#define DATABASERETRIEVALALG_H

#include "larevt/CalibrationDBI/Providers/DBFolder.h"

#include "fhiclcpp/fwd.h"

namespace lariov {

  class IOVTimeStamp;

  /**
     \class DatabaseRetrievalAlg
     User defined class DatabaseRetrievalAlg ... these comments are used to generate
     doxygen documentation!
  */
  class DatabaseRetrievalAlg {

    public:

      /// Constructors
      DatabaseRetrievalAlg(const std::string& foldername, const std::string& url,
			   const std::string& url2="", const std::string& tag="",
			   bool usesqlite=false, bool testmode=false) :
        fFolder{foldername, url, url2, tag, usesqlite, testmode}{}

      explicit DatabaseRetrievalAlg(fhicl::ParameterSet const& p);


      /// Return true if fFolder is successfully updated
      std::optional<DBDataset>
      GetDataset(DBTimeStamp_t ts) const {
        return fFolder.GetDataset(ts);
      }

      /// Get connection information
      const std::string& URL() const {return fFolder.URL();}
      const std::string& FolderName() const {return fFolder.FolderName();}
      const std::string& Tag() const {return fFolder.Tag();}

    protected:
      DBFolder fFolder;

  };
}


#endif
/** @} */ // end of doxygen group
