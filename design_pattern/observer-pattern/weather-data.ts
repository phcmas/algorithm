import { Observer, Subject } from "./subject";

export const NOT_SETTED = Number.NEGATIVE_INFINITY;

export class WeatherData implements Subject {
  private observers: Observer[];
  private temperature: number;
  private humidity: number;
  private pressure: number;

  constructor() {
    this.observers = [];
    this.temperature = NOT_SETTED;
    this.humidity = NOT_SETTED;
    this.pressure = NOT_SETTED;
  }

  registerObserver(observer: Observer): void {
    this.observers.push(observer);
  }

  removeObserver(observer: Observer): void {
    this.observers = this.observers.filter((o) => o !== observer);
  }

  notifyObserver(): void {
    this.observers.forEach((observer) =>
      observer.update(this.temperature, this.humidity, this.pressure)
    );
  }

  mesurementsChanges(): void {
    this.notifyObserver();
  }

  setMesurements(
    temperature: number,
    humidity: number,
    pressure: number
  ): void {
    this.temperature = temperature;
    this.humidity = humidity;
    this.pressure = pressure;
    this.mesurementsChanges();
  }
}
