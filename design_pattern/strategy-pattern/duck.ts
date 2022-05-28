import { FlyBehavior, FlyNoWay, FlyWithWings } from "./fly-behavior";
import { MuteQuack, Quack, QuackBehavior, Squeak } from "./quack-behavior";

export abstract class Duck {
  protected flyBehavior!: FlyBehavior;
  protected quackBehavior!: QuackBehavior;

  abstract display(): void;
  constructor() {}

  performFly() {
    this.flyBehavior.fly();
  }

  performQuack() {
    this.quackBehavior.quack();
  }

  setFlyBehavior(flyBehavior: FlyBehavior) {
    this.flyBehavior = flyBehavior;
  }

  setQuackBehavior(quackBehavior: QuackBehavior) {
    this.quackBehavior = quackBehavior;
  }
}

export class MallardDuck extends Duck {
  constructor() {
    super();
    this.flyBehavior = new FlyWithWings();
    this.quackBehavior = new Quack();
  }

  display(): void {
    console.log("I'm mallard duck");
  }
}

export class ModelDuck extends Duck {
  constructor() {
    super();
    this.flyBehavior = new FlyNoWay();
    this.quackBehavior = new Squeak();
  }

  display(): void {
    console.log("I'm model duck");
  }
}

export class RubberDuck extends Duck {
  constructor() {
    super();
    this.flyBehavior = new FlyNoWay();
    this.quackBehavior = new MuteQuack();
  }

  display(): void {
    console.log("I'm rubber duck");
  }
}
