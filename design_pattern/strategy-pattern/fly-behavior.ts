export interface FlyBehavior {
  fly(): void;
}

export class FlyWithWings implements FlyBehavior {
  fly(): void {
    console.log("I can fly");
  }
}

export class FlyNoWay implements FlyBehavior {
  fly(): void {
    console.log("I cannot fly");
  }
}

export class FlyRocketPowered implements FlyBehavior {
  fly(): void {
    console.log("I can fly with rocket");
  }
}
