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
  -  [Builder](https://github.com/sleevs/Design-Pattern/blob/master/creational/BuilderPattern.cpp)      
  -  [Prototype](https://github.com/sleevs/Design-Pattern/blob/master/creational/Prototype.cpp)

        - Problem:

           There are scenarios where creating new objects can ben resource-intensive and time-consuming process. When an object requires complex initialization or involves costly database operation  , creating a new instance from scratch can be inifficient.
      - Motivation:

           Providing a mechanism to create new objects by cloning or copying existing object . The Prototype pattern aims to improve performance , reduce resource consumption , and promote code reusability.
                Performance improvement , reduce code duplication , flexibility , simplified. Overall , the Proptotype pattern address the problem of resource-intensive object creation , motivates efficient object cloning and offers a solution that improves performance and promotes code reusability.
        
  -  [Singleton](https://github.com/sleevs/Design-Pattern/blob/master/creational/Singleton.cpp)

### Structural patterns

  -  [Adapter](https://github.com/sleevs/Design-Pattern/blob/master/structural/AdapterPattern.cpp)
  -  [Bridge](https://github.com/sleevs/Design-Pattern/blob/master/structural/BridgePattern.cpp)  
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
  -  [State - REFACTORY](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/StatePattern.cpp)
  -  [Strategy - REFACTORY](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/StrategyPattern.cpp)
  -  [Template method - REFACTORY](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/TemplateMethodPattern.cpp)
  -  [Visitor - REFACTORY](https://github.com/sleevs/Design-Pattern/blob/master/behavioral/VisitorPattern.cpp)

      - Problem:

           You have a set class that represent different type of objects , or perform different operations or apply different algorithms on these objects. It's violates the Open-Clodes Principle(SOLID) and requires modifying all class whenever a new operation is added.
      - Motivation:

           The pattern promotes extensibility by allowing the addition of new operations without modifying the existing class (Open-Closed Principle) . This pattern also separate the behavior from the object structure allows to define new operationsor behavior external to the objects themselves.
           Provide a way to extends the behavior of a set of objects without modifying their classes . It promotes maintainability , flexibility , and separation of concerns by keeping the objects focused on their core responsailities and allowing the addition of new behavior.

