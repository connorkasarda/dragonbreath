DRAGON BREATH

-- Summary --

This is a codespace I created for building a soft real-time agent-based
simulation engine. The engine will depend on an Entity Component System (ECS) 
that is built from scratch with the addition of generative AI for the agents. 
Bib file contains sources I used for this project, including an ECS tutorial I 
used for this project.

May consider investigating the use of Python C API. This will allow use of the 
OpenAI package to create generative agents in the soft real-time simulation; the
Large Langauge Models (LLM) used for ChatGPT will be used from OpenAI. However,
there are wrapper APIs available for C++, C#, etc. I might end up using one of 
these for accessing the OpenAI API.

Found out about CAMEL-AI, a solution that provides language agents for research 
projects. I might leverage this for my project to save time and get to a 
product sooner. I'll need to look further through the CAMEL-AI code to make sure 
these language agents are the cognitive language agents I need for this; they 
probably are, just want to make sure that is provided and clear.

-- Implementations --

[x] Build ECS from tutorial/walkthrough
[ ] Incorporate Generative AI Agents from package