#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "set_list.hpp"
#include "set_map.hpp"
#include "set_optimal.hpp"

typedef Set_Opt setType;

/*
* INSERT
*/
SCENARIO( "Sets can be inserted", "[set list]" ) {
	GIVEN( "A empty set" ) {
        Set* set = new setType(100);
        REQUIRE( set->size() == 0 );

        WHEN( "one unique element is inserted" ) {
            bool insertVal = set->insert( 5 );

            THEN( "the size shows one" ) {
                REQUIRE( set->size() == 1 );
            }

            THEN( "the insert val is true" ) {
            	REQUIRE( insertVal );
            }
        }

        WHEN( "multiple emelems are inserted" )  {
        	set->insert( 4 );
        	set->insert( 3 );
        	set->insert( 6 );

        	THEN( "the size shows the number of inserted elements" ) {
        		REQUIRE( set->size() == 3 );
        	} 
        }

        WHEN( "an element is inserted twice" )  {
        	set->insert( 4 );
        	bool secondInsertVal = set->insert( 4 );
        	
        	THEN( "the second insert returns false" ) {
        		REQUIRE( !secondInsertVal );
        	}

        	THEN( "the size only increases by one" ) {
        		REQUIRE( set->size() == 1 );
        	} 
        }
    }
}

/*
* CLEAR
*/
SCENARIO( "Sets can be cleared", "[set list]" ) {
	GIVEN( "A set with values inserted" ) {
		Set* set = new setType(100);
		set->insert(1);
		set->insert(20);
		set->insert(2);

        REQUIRE( set->size() != 0 );

        WHEN( "The set is cleared" ) {
        	set->clear();

        	THEN( "the set size is 0" ) {
        		REQUIRE(set->size() == 0);
        	}

        	THEN( "inserting a previously inserted value returns true" ) {
        		REQUIRE(set->insert(1));
        	}

        	THEN( "looking up a previously inserted value returns false" ) {
        		REQUIRE(!set->lookup(2));
        	}

        	THEN( "trying to remove a previously inserted element returns false" ) {
        		REQUIRE(!set->remove(1));
        	}
        }
	}
}


/*
* REMOVE
*/
SCENARIO( "Set can have elements removed", "[set list]" ) {
	GIVEN("A set with valued inserted") {
		Set* set = new setType(100);
		set->insert(1);
		set->insert(20);
		set->insert(2);

        REQUIRE( set->size() != 0 );

        WHEN( "A existing value is removed" ) {
        	bool removeVal = set->remove(1);

        	THEN( "The size is one less" ) {
        		REQUIRE(set->size() == 2);
        	}

        	THEN( "remove returns true" ) {
        		REQUIRE(removeVal);
        	}

        	THEN( "reinserting the element returns true" ) {
        		REQUIRE(set->insert(1));
        	}
        }

        WHEN( "A non-existing element is removed" ) {
        	int originalSize = set->size();
        	bool removedVal = set->remove(3);

        	THEN( "the remove val is false" ) {
        		REQUIRE(!removedVal);
        	}

        	THEN( "the size doesn't change" ) {
        		REQUIRE(originalSize == set->size());
        	}

        	THEN( "inserting the false removed element succeeds" ) {
        		REQUIRE(set->insert(3));
        	}
        }
	}
}
