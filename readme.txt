░█▀▄░█▀▄░█▀█░█▀▀░█▀█░█▀█░█▀▄░█▀▄░█▀▀░█▀█░▀█▀░█░█
░█░█░█▀▄░█▀█░█░█░█░█░█░█░█▀▄░█▀▄░█▀▀░█▀█░░█░░█▀█
░▀▀░░▀░▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀░░▀░▀░▀▀▀░▀░▀░░▀░░▀░▀

-- Summary --

This is a codespace I created for building a soft real-time agent-based
simulation engine. The engine will depend on an Entity Component System (ECS) 
that is built from scratch with the addition of generative AI for the agents. 
Bib file contains sources I used for this project, including an ECS tutorial I 
used for this project.

Cognitive Language Agents (CLA) will be a focus of this project. The plan of 
attack is to either prompt an already existing LLM API via HTTP requests or 
operate off of an LLM I make from scratch. Then, a cognitive architecture will
leverage prompt engineering when communicating with the LLM. The end result 
should be CLAs that live and interact in a virtual environment. For example: 
classroom, coffee shop, library, village, etc.

-- Implementations --

[x] Build ECS from tutorial/walkthrough
[ ] Prompter communication with LLM API
[ ] CLA incorporation into ECS
