# Design Pattern implemented in C++

This a demostration of design patterns with objective to mature the understanding of software design using the C++.



### Creational patterns

  -  [Factory Method](https://github.com/sleevs/Design-Pattern/blob/master/creational/FactoryMethod.cpp)

      - Problem:
      
           There are scenario where you need to create objets to different classes that implement a common interface or inherit from a common base class or when you need create objects in which the type of object is made in runtime.
      - Motivation:

           Selecting which subclass to use.
                  Loosely coucpling the underlying creation implementation.
           Some solution is produce instances of objects based on a set of input parameters focused on supporting class polymorphism.

   
  -  [Abstract factory](https://github.com/sleevs/Design-Pattern/blob/master/creational/AbstractFactory.cpp)
       - Problem:
          
         There are scenarios where we need to create families of related or dependent objects . Any way , directly instantianting these objects or tightly coupling them in client code can lead to dependencies and code fragility. Moreover , introducing new families of objects or modifying existing one becomes difficult and erro-prone.
         
       - Motivation:

         Abstract Factory pattern provide an interface for creating families of related or dependent objects without sprcifying their concrete class . It decouples the client code from the specific implementations and allows for easy substitution of object families . It promotes flexibility , extensibility and maintainability.
         
  -  [Builder](https://github.com/sleevs/Design-Pattern/blob/master/creational/BuilderPattern.cpp)      
  -  [Prototype](https://github.com/sleevs/Design-Pattern/blob/master/creational/Prototype.cpp)

        - Problem:

           There are scenarios where creating new objects can ben resource-intensive and time-consuming process. When an object requires complex initialization or involves costly database operation  , creating a new instance from scratch can be inifficient.
      - Motivation:

           Providing a mechanism to create new objects by cloning or copying existing object . The Prototype pattern aims to improve performance , reduce resource consumption , and promote code reusability.
                Performance improvement , reduce code duplication , flexibility , simplified. Overall , the Proptotype pattern address the problem of resource-intensive object creation , motivates efficient object cloning and offers a solution that improves performance and promotes code reusability.
        
  -  [Singleton](https://github.com/sleevs/Design-Pattern/blob/master/creational/Singleton.cpp)
      
      - Problem:
      
           There scenarios where we need to ensure that a class has only one instance throughout the entire application.
            For example , when dealing with shared resource , configuration setting or objects that are expensive to create. So then multiple instance can lead to inconsistance behavior and resource wastage or conclicts.
        Ensuring a single instance of class become a challenging with multiple components or threads requires acces to it. 
        
      - Motivation:

          Singleton pattern is to provide a centralized and controlled way of creating and accessing instance of a class. It ensures that the instance is shared among multiple components , maintains a global state or manager resources effeciently.
   
### Structural patterns

  -  [Adapter](https://github.com/sleevs/Design-Pattern/blob/master/structural/AdapterPattern.cpp)
  -  [Bridge](https://github.com/sleevs/Design-Pattern/blob/master/structural/BridgePattern.cpp)

       - Problem:

         There are situations where we have an abstraction that has muliple implementation. If we directly couple the abastraction with implementation any change to either the abstraction or the implementation would require modifying the other , leading to a lack of flexibility and increased complexity.
   
       - Motivation:

         The Bridge pattern is to separate the abstraction from its implementation , allowing them to evolve independently. It enable loose coupling between the abstraction and its implementation , promoting flexibility , extensibility and easier maintenance.
         
  -  [Composite](https://github.com/sleevs/Design-Pattern/blob/master/structural/CompositePattern.cpp)

      - Problem:

           There are scenario where we need to work with a hierachical strucuture that consist of both individual objets and collections of objets. Threating individual object and goups of objects differently can lead to complex and repetitive code.
        
      - Motivation:

          The Composite pattern provide a unified way to working tih individual objects and groups of objects . It allows you code and enabling transparency in manipulation of hirarchical structure .
        
  -  [Decorator](https://github.com/sleevs/Design-Pattern/blob/master/structural/DecoratorPattern.cpp)

      - Problem:

           You want to transparently and dynamically add responsabilities to objects without affecting other objects.
      - Motivation:
      
           Some times we want to add responsabilities to individual objects but no entire class.
           Decorator approch allow attach additional  responsabilities to an object dynamically  and provide a flexible alternative to SubClass for extending functionality.
        
  -  [Facade](https://github.com/sleevs/Design-Pattern/blob/master/structural/FacadePattern.cpp)
  -  [Flyweight](https://github.com/sleevs/Design-Pattern/blob/master/structural/FlyweightPattern.cpp)
  -  [Proxy](https://github.com/sleevs/Design-Pattern/blob/master/structural/ProxyPattern.cpp)


### Behavioral patterns

  -  [Chain of responsibility](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/ChainOfResponsabilityPattern.cpp)
  -  [Command](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/CommandPattern.cpp)
  -  [Iterator](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/IteratorPattern.cpp)
  -  [Mediator](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/MediatorPattern.cpp)
  -  [Memento](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/MementoPattern.cpp)
  -  [Observer](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/ObserverPattern.cpp)
  -  [State - REFACTORY - TO DO](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/StatePattern.cpp)
  -  [Strategy - REFACTORY - TO DO](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/StrategyPattern.cpp)
        
        - Problem:

          There are situations where we need to implement different algorithms or behaviors , that can be dynamically selected at runtime . Any way , if we hard-code these algorithms or behaviors directly into the client codes , it can lead to code duplication, code hard and inflexibility , difficulty in modifying or adding new behaviors.

        - Motivation:

          Strategy pattern provide a way to encaptulation and interchange algorithms or behaviors at runtime. It allows us to define a familty of algorithms or behaviors , encapsulates each one separetely and make then interchangeable without modifying the client code . This promotes code reuse , flexbility and easier maintenance .
  -  [Template method - REFACTORY - TO DO](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/TemplateMethodPattern.cpp)

      - Problem:

        There are situations where we need to define an algorithm with fixed structure but with certain steps that can vary across implementation. If we implement the entire algorithm in each SubClass , it can lead to code duplication and maintenance challenge.

      - Motivation:

        The Template Method pattern define the skeleton of an algorithm in an operation , deferring some steps to SubClass and let's the SubClass redefine certain steps of algorithm without changing the algorithm's structure.

          
  -  [Visitor - REFACTORY - TO DO](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/VisitorPattern.cpp)

      - Problem:

           You have a set class that represent different type of objects , or perform different operations or apply different algorithms on these objects. It's violates the Open-Clodes Principle(SOLID) and requires modifying all class whenever a new operation is added.
      - Motivation:

           The pattern promotes extensibility by allowing the addition of new operations without modifying the existing class (Open-Closed Principle) . This pattern also separate the behavior from the object structure allows to define new operationsor behavior external to the objects themselves.
           Provide a way to extends the behavior of a set of objects without modifying their classes . It promotes maintainability , flexibility , and separation of concerns by keeping the objects focused on their core responsailities and allowing the addition of new behavior.

