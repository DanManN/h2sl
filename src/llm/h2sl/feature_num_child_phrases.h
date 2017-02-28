/**
 * @file    feature_num_child_phrases.h
 * @author  Thomas M. Howard (tmhoward@csail.mit.edu)
 *          Matthew R. Walter (mwalter@csail.mit.edu)
 * @version 1.0
 *
 * @section LICENSE
 *
 * This file is part of h2sl.
 *
 * Copyright (C) 2014 by the Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see
 * <http://www.gnu.org/licenses/gpl-2.0.html> or write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * @section DESCRIPTION
 *
 * The interface for a class used to check for a match with a phrase's number
 * of words
 */

#ifndef H2SL_FEATURE_NUM_CHILD_PHRASES_H
#define H2SL_FEATURE_NUM_CHILD_PHRASES_H

#include <iostream>

#include <h2sl/feature.h>

namespace h2sl {
  class Feature_Num_Child_Phrases: public Feature {
  public:
    Feature_Num_Child_Phrases( const bool& invert = false, const unsigned int& numChildPhrases = 0 );
    Feature_Num_Child_Phrases( xmlNodePtr root );
    virtual ~Feature_Num_Child_Phrases();
    Feature_Num_Child_Phrases( const Feature_Num_Child_Phrases& other );
    Feature_Num_Child_Phrases& operator=( const Feature_Num_Child_Phrases& other );

    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world );
    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world, const Grounding* context );


    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    virtual void from_xml( xmlNodePtr root );

    inline unsigned int& num_child_phrases( void ){ return _num_child_phrases; };
    inline const unsigned int& num_child_phrases( void )const{ return _num_child_phrases; };

    virtual inline const feature_type_t type( void )const{ return FEATURE_TYPE_LANGUAGE; };

  protected:
    unsigned int _num_child_phrases;

  private:

  };
  std::ostream& operator<<( std::ostream& out, const Feature_Num_Child_Phrases& other );
}

#endif /* H2SL_FEATURE_NUM_CHILD_PHRASES_H */
