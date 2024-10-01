#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <vector>
#include "doctest.h"
#include "Card.hpp"
#include "Deck.hpp"
#include "GameBoard.hpp"
#include "GameLogic.hpp"
#include "Player.hpp"
#include "Property.hpp"

using namespace std;

// Testing Card class and its derived classes
TEST_CASE("Card Tests") {
    Player player("diaa");

    // Test specific cards
    goBackCard goBack;
    goToJailCard goToJail;
    advanceToGoCard advanceToGo;
    poorTaxCard poorTax;

    SUBCASE("Go Back Card Test") {
        player.setPostion(5);
        goBack.applyEffect(player);
        CHECK(player.getPosition() == 2);  // Should move back 3 spaces
    }

    SUBCASE("Go To Jail Card Test") {
        goToJail.applyEffect(player);
        CHECK(player.inJail() == true);  // Player should be in jail
    }

    SUBCASE("Advance To Go Card Test") {
        advanceToGo.applyEffect(player);
        CHECK(player.getPosition() == 0);  // Should go to the "Go" position
    }

    SUBCASE("Poor Tax Card Test") {
        int initialBalance = player.getBalance();
        poorTax.applyEffect(player);
        CHECK(player.getBalance() == initialBalance - 15);  // Player pays $15 tax
    }
}

// Test Suite for Player class
TEST_CASE("Player Tests") {
    Player player("John Doe");

    SUBCASE("Test Player Initialization") {
        CHECK(player.getName() == "John Doe");
        CHECK(player.getBalance() == 1500);  // Default balance
        CHECK(player.getPosition() == 0);    // Default position
        CHECK(player.inJail() == false);     // Player should not be in jail initially
        CHECK(player.getBroke() == false);   // Player should not be broke initially
    }

    SUBCASE("Test Player Movement") {
        player.move(5);
        CHECK(player.getPosition() == 5);  // Player should move 5 spaces

        player.move(10);
        CHECK(player.getPosition() == 15); // Player should move an additional 10 spaces
    }

    SUBCASE("Test Player Going to Jail") {
        player.moveToJail();
        CHECK(player.inJail() == true);    // Player should be in jail
        CHECK(player.getPosition() == 10); // Assume jail is at position 10
    }

    SUBCASE("Test Player Paying and Getting Paid") {
        int initialBalance = player.getBalance();

        // Test paying
        player.pay(200);
        CHECK(player.getBalance() == initialBalance - 200);

        // Test getting paid
        player.getPaid(500);
        CHECK(player.getBalance() == initialBalance - 200 + 500);
    }

    SUBCASE("Test Player Buying Property") {
        Property property("Boardwalk", "dark blue", 400, 50, 200, 1000, nullptr);
        player.buyProperty(property);
        
        CHECK(player.getBalance() == 1100);  // Player should have spent $400
        CHECK(property.getOwner() == &player);  // Player is now the owner of the property
    }
}
