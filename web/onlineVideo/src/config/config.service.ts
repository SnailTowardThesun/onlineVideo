import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

export interface OnlineVideoWebConfig {
  baseUrl: string;
}

@Injectable({
  providedIn: "root",
})
export class ConfigService {
  public config : OnlineVideoWebConfig = {
    baseUrl: '127.0.0.1:5000'
  };

  constructor(private http: HttpClient) { }

  
}