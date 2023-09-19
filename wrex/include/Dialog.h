/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <vector>

#include "Exception.h"
#include "RandomNumberGenerator.h"

/**
* The Dialoger interface used to get the dialog,
* depending on the state or context of the Boss.
*/

class Dialoger {
 public:
    virtual ~Dialoger() {}
    virtual const std::vector<const char*> get() = 0;
};

/**
* A class to retreive a voiceline at random from
* a handful of predetermined responses, depending
* on the state or context of the Boss.
*/

class Dialog {
 public:
    /**
    * The destructor for Dialog.
    */
    virtual ~Dialog() {}

    /**
    * A response to the Exorcist, depending on the state.
    * @param[in] d the pointer to the Dialoger to get voicelines from.
    */
    void response(Dialoger* dialoger) {
        if (dialoger == nullptr)
            throw invalid_parameter_error("Dialoger is a nullptr");

        const std::vector<const char*> dialog = dialoger->get();

        int size = dialog.size() - 1;
        int rng = getRandomNumber(0, size);

        std::cout << dialog[rng] << std::endl;
    }
};

/**
* A data class for Vengeful dialog.
*/

struct VengefulDialoger : public Dialoger {
 public:
    /**
    * The default constructor for VengefulDialoger.
    */
    VengefulDialoger() {}

    /**
    * Get a voiceline for the Vengeful dialog.
    */
    virtual const std::vector<const char*> get() {
        return dialog;
    }

 private:
    const std::vector<const char*> dialog = {
        "Die! Die, die! Exorcist are killers, nothing less!",
        "Burn! Burn, you fiend!",
        "All Exorcists must die!",
        "It's all your fault.",
        "You're better off dead!",
    };
};

/**
* A data class for Hostile dialog.
*/

struct HostileDialoger : public Dialoger {
 public:
    /**
    * The default constructor for HostileDialoger.
    */
    HostileDialoger() {}

    /**
    * Get a voiceline for the Hostile dialog.
    */
    virtual const std::vector<const char*> get() {
        return dialog;
    }

 private:
    const std::vector<const char*> dialog = {
        "You are not wanted here!",
        "An Exorcist is an Exorcist, even in a dream...",
        "You've been exorcising and killing to your heart's content.",
        "I will kill you without hesitation.",
        "You'll pay for this.",
    };
};

/**
* A data class for Friendly dialog.
*/

struct FriendlyDialoger : public Dialoger {
 public:
    /**
    * The default constructor for FriendlyDialoger.
    */
    FriendlyDialoger() {}

    /**
    * Get a voiceline for the Friendly dialog.
    */
    virtual const std::vector<const char*> get() {
        return dialog;
    }

 private:
    const std::vector<const char*> dialog = {
        "Farewell, good Exorcist. May you find your worth in the waking world.",
        "Promise to stay safe.",
        "You’ve got a heart of Gold. Don’t let them take it from you.",
        "You were at my side, all along",
        "Thank you...",
    };
};

/**
* A data class for Dead dialog.
*/

struct DeadDialoger : public Dialoger {
 public:
    /**
    * The default constructor for DeadDialoger.
    */
    DeadDialoger() {}

    /**
    * Get a voiceline for the Dead dialog.
    */
    virtual const std::vector<const char*> get() {
        return dialog;
    }

 private:
    const std::vector<const char*> dialog = {
        "...",
        "... ...",
        "Foul Exorcist...",
        "*groan*",
        "Why... me... Dear gods, what have I done? Save me, please...",
    };
};

#endif // DIALOG_H
