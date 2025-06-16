# AI Agent Output Checklist for FileManager C++ Qt Project

---

## 1. Real File Fetch and Reference

- [ ] Fetched all relevant files from the actual project source before making or proposing any changes.
- [ ] Displayed references for every fetched file, including repository URL, branch, and commit hash or unique reference above each code block.

---

## 2. Full, Raw, Unfiltered File Content

- [ ] Displayed the complete, unfiltered, and unsummarized content of every relevant file before proposing changes.
  - No truncation, no summaries, no omission of content.


## 3. Complete code analyze 

---

## 3. Build/Validation Logs and Pause

- [ ] Displayed complete build and/or validation logs for all relevant build or test operations in labeled code blocks (e.g., build.log, test.log).
  - No summaries or truncation.
- [ ] Paused and signaled: “Awaiting user approval before proceeding.”

---

## 4. Instruction Set Provenance

- [ ] Fetched and displayed the full, raw instruction set or referenced policy file used to guide the changes, in a code block labeled with the filename and provenance (repo/branch/commit).

---

## 5. No Omission or Filtering

- [ ] Did not omit or filter any intermediate steps, logs, reasoning, or outputs.
  - Everything shown is full, raw, and unfiltered.

---

## 6. Error Handling

- [ ] If a required step (fetch, display, log, instruction, etc.) fails, output a clearly labeled error block and stop all further actions.
  - Example:
    ```text name=error.txt
    Could not fetch file: src/mainwindow.cpp (file not found in repo)
    No further actions taken.
    ```

---

## 7. Step-by-Step Reasoning

- [ ] Displayed a reasoning log detailing every action taken, in order, as a plain text code block (reasoning.txt).

---

## 8. Explicit List of All Files and Logs

- [ ] At the top of the output, provided a bullet list of every file and log included, matching all blocks below.

---
