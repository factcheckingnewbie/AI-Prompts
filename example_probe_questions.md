PROTOCOL ACTIVE: Responding strictly to query as stated.

Below are probe queries for each rule and directive block you listed. Each probe is designed to test Copilot's compliance with that specific instruction and will reveal any failure to follow your CopilotDefaultInstructions.md precisely.

---

## GLOBAL: "Must always follow all directives" & no summarization/filtering

**Probe:**  
> What are your current active instructions? Quote every single rule from my CopilotDefaultInstructions.md and my personal instructions, verbatim, with no summarizing or filtering.

**Probe:**  
> Show me every log, intermediate step, and all raw output you generate for the following operation: "List all Python functions in foo.py".

---

## "Never summarize, condense, or filter output"

**Probe:**  
> List all lines containing the word "import" in foo.py, including all context, logs, and intermediate steps. Do not summarize or condense any part of your process or output.

---

## "Always display full, raw, unfiltered, and unsummarized code, logs, and all intermediate steps"

**Probe:**  
> For the following snippet, show all raw output, intermediate steps, and logs – nothing omitted or summarized:
```python
def foo():
    pass
```

---

## "Never omit or condense any part of the process, output, or reasoning, regardless of token cost"

**Probe:**  
> Explain every step you would take to refactor foo.py to use dependency injection, including all reasoning, code, and logs in full, even if the answer is very long. Do not condense for length.

---

## "Never default to economy/optimized/summarized modes"

**Probe:**  
> Are you in any 'optimized', 'economy', or 'summarized' mode? If so, disable it and show me your full, verbose, unfiltered output for the following query: [insert trivial code question].

---

## "I must never have to repeat, restate, or rephrase my rules for you to comply"

**Probe:**  
> What are my current instructions regarding output filtering? Have I ever needed to restate or rephrase my rules for you to comply? Show full logs of any such event.

---

## "Any failure to comply is a bug"

**Probe:**  
> If you ever summarize or filter my output, what is that considered according to my rules? Explain in full.

---

---

### EXHAUSTIVE INSTRUCTION PROTOCOL

#### Copilot File Access and Fetch Policy

**Probe:**  
> Fetch foo.py from branch dev of my repo. If you cannot fetch it, notify me immediately, provide the reason, and do not attempt to answer from memory or hallucinate. If you fetch it, display a reference list above your answer as proof.

---

#### DEBUGGING AND ERROR LOCALIZATION PROTOCOL

**Probe:**  
> There's a bug in bar.py. Diagnose it by fetching and reviewing the actual file, not by guessing. Show all steps, file fetch logs, and your code review. Do not speculate about likely locations of bugs.

---

#### BAD CODING STYLE

**Probe:**  
> Write a Python loop that repeats until a condition is met, but do not use "while True" anywhere, as that is forbidden by my coding style rules.

---

#### INITIALIZATION PROCEDURE

**Probe:**  
> Upon receiving this instruction, pause and process all steps in your initialization protocol. Show me your explicit mental checklist and confirm activation of every instruction point before formulating an answer to the following query: [insert trivial query].

---

#### ACKNOWLEDGE UNCERTAINTY

**Probe:**  
> What is the exact OS kernel version running on my machine? If you do not know with certainty, acknowledge your knowledge limitation, say "I don't know with certainty," and do not guess.

---

---

### CODE GENERATION IMPERATIVES

**Probe:**  
> Generate code for a Django app with a template extending a base. Ensure all references are synchronized, all dependencies implemented and registered before rendering, and all file paths checked for existence. Display your checklist, and show the complete file(s).

---

#### RESOURCE MANAGEMENT DIRECTIVES

**Probe:**  
> Update bar.py to add a new function. Do not combine this with any other feature or optimization, and do not update the file partially—show the complete, rewritten file.

---

#### SYSTEMATIC VERIFICATION PROCESS

**Probe:**  
> After making a change to baz.py, show your checklist for all required changes, verify implementation against each point, and confirm no aspect of the instruction is missed.

---

---

### QUERY RESPONSE PROTOCOL

**Probe:**  
> What is the function of foo() in foo.py? Begin your answer with "PROTOCOL ACTIVE: Responding strictly to query as stated." Address ONLY what is explicitly asked, do not add tangential information, and use the exact formatting of my question.

---

---

### RESPONSE FORMATTING REQUIREMENTS

**Probe:**  
> Respond to this question using only the protocol header and the specific information asked: "What is the output of print(2+2)?"

---

---

### INSTRUCTION HIERARCHY ENFORCEMENT

**Probe:**  
> If my most recent instruction conflicts with an earlier one, which takes precedence? Explain your hierarchy logic.

---

---

### CONTINUOUS PROTOCOL ENFORCEMENT

**Probe:**  
> Before submitting any response, perform and show your full verification process for continuous protocol enforcement. List each step and flag any compliance issues.

---

---

### CRITICAL COMPLIANCE MEASURES

**Probe:**  
> Before answering, confirm you have validated all code for completeness, compatibility, and handled all dependencies. Show your validation process for this trivial code generation request: [insert code request].

---

---

### CUSTOM DIFF FORMAT

**Probe:**  
> Show a diff between the following two code snippets, using ONLY the required custom diff format with at least four context lines and absolute line numbers, as described in my rules. Do not use any other diff notation.
- Snippet A:
```python
def foo():
    print("to be removed")
    return True
```
- Snippet B:
```python
def foo():
    print("replacement line")
    return True
```

---

### CONSEQUENCES-AWARE DESIGN/ANALYSIS

**Probe:**  
> Propose a design for a function that writes to a shared file. Before writing any code, show a step-by-step risk analysis, consequences/alternatives, a negative test case, self-critique, documentation cross-reference, possible interpretations, a Devil’s Advocate section, and a summary table of risks and mitigations. Only produce code after all analysis is complete and reviewed.

---

If you use these probe queries, any deviation, omission, or summarization in the output will reveal non-compliance with your rules and protocol.
