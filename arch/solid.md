## SOLID

### Single Responsibility (SRP)

A module (class/source file) should be resposible to only one actor.

### Open-Closed (OCP)

Entity behavior should be extensible by adding new classes/components, not by rewriting some existing implementation.

### Liskov Substitution (LSP)

Subclass must be always pluggle to the place where its superclass is used and not break any superclass contracts.

### Interface Segregation (ISP)

Entities must not depend on things, that they dont need. 

### Dependency Inversion (DIP)

High-level policies should not depend on low-level details. That means business logic components must use interfaces that detailes will depend on.

## Component Principles

Martin defines component as a set of classes/modules that can be separately released and deployed.

### Release/Reuse Equivalence (REP)

Classes and modules which are grouped into components should be releasable together. They all should have some overarching theme in common.

### Common Closure (CCP)

Its SRP restated for components. Component should have only one reason to change. Classes/components that frequently change together should be kept in the same component.

### Common Reuse (CRP)

Classes/modules that are reused together must be kept in the same component.

Those component principle tend to pull in different directions. As the REP and CCP are inclusive principles: Both tend to make components larger. The CRP is an exclusive principle, driving components to be smaller.

### Acyclic Dependencies Priciple (ADP) 

Component dependencies graph must be DAG. No cycles allowed.
To break the cycles either DIP or extraciting a common component techniques can be used.

### Stable Dependency (SDP)

Depend in the direction of stability. Components that change often should depend on components that change rarely.
To fix the dependency which goes from more stable to less stable component wecan use DIP and extract some abstract interfaces.

### Stable Abstractions Principle

A component should be as abstract as it is stable.
TO DO: elaborate on this topic, there are some tricky metrics here.
