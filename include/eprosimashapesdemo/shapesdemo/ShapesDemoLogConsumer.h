// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes Demo.
//
// eProsima Fast DDS Shapes Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes Demo. If not, see <https://www.gnu.org/licenses/>.

/**
 * @file ShapesDemoLogConsumer.h
 */

#ifndef SHAPESDEMOLOGCONSUMER_H_
#define SHAPESDEMOLOGCONSUMER_H_

#include <memory>

#include <fastdds/dds/log/Log.hpp>

#include <eprosimashapesdemo/qt/mainwindow.h>

class ShapesDemoLogConsumer : public LogConsumer
{
public:

    static void register_new_consumer(
            MainWindow* window)
    {
        std::unique_ptr<LogConsumer> log_consumer(new ShapesDemoLogConsumer(window));
        Log::RegisterConsumer(std::move(log_consumer));
    }

    explicit ShapesDemoLogConsumer(
            MainWindow* window)
        : main_window_(window)
    {
    }

    virtual ~ShapesDemoLogConsumer() = default;

    /** \internal
     * Called by Log to ask us to consume the Entry.
     * @param Log::Entry to consume.
     */
    void Consume(
            const Log::Entry& entry) override
    {
        // Format message
        print_header(stream_, entry, false);
        print_message(stream_, entry, false);
        print_context(stream_, entry, false);
        
        // Add message to Output tab
        main_window_->addMessageToOutput(QString(stream_.str().c_str()));
        
        // Clear stringstream
        stream_.str("");
    }

private:

    MainWindow* main_window_;
    std::stringstream stream_;
};



#endif /* SHAPESDEMOLOGCONSUMER_H_ */
