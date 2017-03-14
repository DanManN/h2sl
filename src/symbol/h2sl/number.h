/**
 * @file number.h
 * 
 * @brief
 * 
 * a class used to describe a spatial relationship
 */

#ifndef H2SL_NUMBER_H
#define H2SL_NUMBER_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/grounding.h"
#include "h2sl/object.h"


namespace h2sl {
  /**
   * Number class definition
   */
  class Number : public Grounding {
  public:

    Number( const int& value = 0 );
    Number( const Number& other );
    Number( xmlNodePtr root );
    virtual ~Number();
    Number& operator=( const Number& other );
    bool operator==( const Number& other )const;
    bool operator!=( const Number& other )const;
    virtual Number* dup( void )const;

    virtual bool matches_class_name( const std::string& arg )const{ return ( arg == "number" ); };
    virtual void scrape_grounding( const World * world, std::vector< std::string >& classNames, std::map< std::string, std::vector< std::string > >& stringTypes, std::map< std::string, std::vector< int > >& intTypes )const;
    static void fill_search_space( const Symbol_Dictionary& symbolDictionary, const World* world, std::map< std::string, std::pair< std::string, std::vector< Grounding* > > >& searchSpaces, const symbol_type_t& symbolType );
 
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline int& value( void ){ return get_prop< int >( _int_properties, "value" ); };
    inline const int& value( void )const{ return get_prop< int >( _int_properties, "value" ); };

    static std::string class_name( void ){ return "number"; };

  protected:

  private:

  };

  /** 
   * Number class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Number& other );
}

#endif /* H2SL_NUMBER_H */
