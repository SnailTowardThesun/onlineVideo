import { BrowserModule } from '@angular/platform-browser';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { NgModule } from '@angular/core';

import { MatNativeDateModule } from '@angular/material/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ChannelComponent } from './channel/channel.component';
import { IndexComponent } from './index/index.component';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';

import { MaterialModule } from './material-module';
import { NavigateComponent, NavUserDialog } from './navigate/navigate.component';
import { MatDialogModule } from '@angular/material/dialog';

@NgModule({
  declarations: [
    AppComponent,
    ChannelComponent,
    IndexComponent,
    NavigateComponent,
    NavUserDialog,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    FormsModule,
    MatNativeDateModule,
    BrowserAnimationsModule,
    MaterialModule,
    MatDialogModule
  ],

  entryComponents: [
    NavUserDialog
  ],

  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
